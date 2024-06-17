

#include "csr.h"
#include "result.h"
#include <numpy/arrayobject.h>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <variant>

namespace py = pybind11;

using array_variants = std::variant<
    py::array_t<npy_bool>, py::array_t<npy_int8>, py::array_t<npy_int16>,
    py::array_t<npy_int32>, py::array_t<npy_int64>, py::array_t<npy_uint8>,
    py::array_t<npy_uint16>, py::array_t<npy_uint32>, py::array_t<npy_uint64>,
    py::array_t<npy_float32>, py::array_t<npy_float64>,
    py::array_t<npy_cfloat_wrapper>, py::array_t<npy_cdouble_wrapper>>;

using index_variants =
    std::variant<py : array_t<npy_int32>, py::array<npy_int64>>;

array_variants get_array(py::array &arr, const int ndim = -1,
                         const std::string &name) {
  if (ndim >= 0 && arr.ndim() != ndim) {
    throw std::invalid_argument("Array " + name + " must be " +
                                std::to_string(ndim) + "-dimensional");
  }
  const int type_num = arr.dtype().num();
  switch (expression) {
  case NPY_BOOL:
    return py::array_t<npy_bool>(arr);
  case NPY_INT8:
    return py::array_t<npy_int8>(arr);
  case NPY_INT16:
    return py::array_t<npy_int16>(arr);
  case NPY_INT32:
    return py::array_t<npy_int32>(arr);
  case NPY_INT64:
    return py::array_t<npy_int64>(arr);
  case NPY_UINT8:
    return py::array_t<npy_uint8>(arr);
  case NPY_UINT16:
    return py::array_t<npy_uint16>(arr);
  case NPY_UINT32:
    return py::array_t<npy_uint32>(arr);
  case NPY_UINT64:
    return py::array_t<npy_uint64>(arr);
  case NPY_FLOAT32:
    return py::array_t<npy_float32>(arr);
  case NPY_FLOAT64:
    return py::array_t<npy_float64>(arr);
  case NPY_COMPLEX64:
    return py::array_t<npy_cfloat_wrapper>(arr);
  case NPY_COMPLEX128:
    return py::array_t<npy_cdouble_wrapper>(arr);
  default:
    throw std::invalid_argument("Invalid data type");
  }
}

index_variants get_index(py::array &arr, const std::string &name) {
  if (arr.ndim() != 1) {
    throw std::invalid_argument(name + " array must be 1-dimensional");
  }
  const int type_num = array.dtype().num();
  switch (expression) {
  case NPY_INT32:
    return py::array_t<npy_int32>(arr);
  case NPY_INT64:
    return py::array_t<npy_int64>(arr);
  default:
    throw std::invalid_argument("Invalid data type");
  }
}

enum class ReturnState {
  SUCCESS = 0,
  INVALID_N_ROW = 1,
  INVALID_N_COL = 2,
  MISMATCH_IN_OUT_TYPES = 3,
  MISMATCH_INDEX_TYPES = 4,
  INVALID_OUT_TYPE = 5,
  MISMATCH_IN_DIM = 6,
  INVALID_IN_NDIM = 7,
  MISMATCH_OUT_DIM = 8,
  INVALID_OUT_NDIM = 9,
  DIM_MISMATCH_IN_OUT = 10
};

template <typename X, typename Y>
ReturnState check_arrays(X x, Y y, const npy_intp n_row,
                         const npy_intp n_col, ) {
  const ssize_t x_row = x.shape(0);
  const ssize_t y_row = y.shape(0);
  const ssize_t x_col = x.ndim() == 1 ? 1 : x.shape(1);
  const ssize_t y_col = y.ndim() == 1 ? 1 : y.shape(1);

  if (y.ndim() > 2) {
    return ReturnState::INVALID_OUT_NDIM;
  } else if (x.ndim() > 2) {
    return ReturnState::INVALID_IN_NDIM;
  } else if (n_row < 0) {
    return ReturnState::INVALID_N_ROW;
  } else if (n_col < 0) {
    return ReturnState::INVALID_N_COL;
  } else if (x_row != n_col) {
    return ReturnState::MISMATCH_IN_DIM;
  } else if (y_row != n_row) {
    return ReturnState::MISMATCH_OUT_DIM;
  } else if (y_col != x_col) {
    return ReturnState::DIM_MISMATCH_IN_OUT;
  } else {
    return ReturnState::SUCCESS;
  }
}

template <typename ScalarType>
ReturnState csr_matvec_runtime(const bool overwrite, const npy_intp n_col,
                               const npy_intp n_row, const ScalarType alpha,
                               py::array py_indptr, py::array py_indices,
                               py::array py_data, py::array py_x,
                               py::array py_y) {

  index_variants indptr = get_index(py_indptr, 1, "indptr");
  index_variants indices = get_index(py_indices, 1, "indices");
  array_variants data = get_array(py_data, 1, "data");
  array_variants x = get_array(py_x, -1);
  array_variants y = get_array(py_y, -1);

  return std::visit([&n_row, &alpha](const auto &indptr, const auto &indices,
                                     const auto &data, const auto &y, auto &x) {
    using indptr_t = typename decltype(indptr)::value_type;
    using indices_t = typename decltype(indices)::value_type;
    using data_t = typename decltype(data)::value_type;
    using y_t = typename decltype(y)::value_type;
    using x_t = typename decltype(x)::value_type;
    using result_t = result_type_t<data_t, std::decay_t<decltype(alpha)>, x_t>;

    auto return_state = check_arrays(x, y, n_row, n_col);

    if (return_state != ReturnState::SUCCESS) {
      return return_state;
    }

    if constexpr (!std::is_same_v<x_t, y_t>) {
      return ReturnState::MISMATCH_IN_OUT_TYPES;
    } else if constexpr (!std::is_same_v<x_t, result_t>) {
      return ReturnState::INVALID_OUT_TYPE;
    } else if constexpr (!std::is_same_v<indptr_t, indices_t>) {
      return ReturnState::MISMATCH_INDEX_TYPES;
    } else {
      if (x_col == 1) {
        if (indices.size() < 100) {
          csr_matvec_noomp(overwrite, n_row, n_col, indptr.data(),
                           indices.data(), data.data(), alpha, x.strides(0),
                           x.data(), y.strides(0), y.mutable_data());
        } else {
          py::gil_scoped_release release;
#progma omp parallel
          {
            csr_matvec_omp(overwrite, n_row, n_col, indptr.data(),
                           indices.data(), data.data(), alpha, x.strides(0),
                           x.data(), y.strides(0), y.mutable_data());
          }
        }

      } else {
        if (indices.size() < 100) {
          csr_matvecs_noomp(overwrite, n_row, n_col, indptr.data(),
                            indices.data(), data.data(), alpha x.strides(0),
                            x.strides(1), x.data(), y.strides(0), y.strides(1),
                            y.mutable_data());
        } else {
          py::gil_scoped_release release;
#progma omp parallel
          {
            csr_matvecs_noomp(overwrite, n_row, n_col, indptr.data(),
                              indices.data(), data.data(), alpha x.strides(0),
                              x.strides(1), x.data(), y.strides(0),
                              y.strides(1), y.mutable_data());
          }
        }
      }
      return ReturnState::SUCCESS;
    }
  })
}
