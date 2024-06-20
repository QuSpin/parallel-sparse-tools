

#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <variant>

#include "complex_ops.h"
#include "csr.h"
#include "result.h"

namespace py = pybind11;

using array_variants = std::variant<
    py::array_t<bool>, py::array_t<int8_t>, py::array_t<int16_t>,
    py::array_t<int32_t>, py::array_t<int64_t>, py::array_t<uint8_t>,
    py::array_t<uint16_t>, py::array_t<uint32_t>, py::array_t<uint64_t>,
    py::array_t<float>, py::array_t<double>, py::array_t<long double>,
    py::array_t<cfloat>, py::array_t<cdouble>, py::array_t<clongdouble>>;

using index_variants = std::variant<py::array_t<int32_t>, py::array_t<int64_t>>;

array_variants get_array(py::array &arr) {
  const int type_num = arr.dtype().num();
  switch (type_num) {
  case py::detail::npy_api::NPY_BOOL_:
    return py::array_t<bool>(arr);
  case py::detail::npy_api::NPY_INT8_:
    return py::array_t<int8_t>(arr);
  case py::detail::npy_api::NPY_INT16_:
    return py::array_t<int16_t>(arr);
  case py::detail::npy_api::NPY_INT32_:
    return py::array_t<int32_t>(arr);
  case py::detail::npy_api::NPY_INT64_:
    return py::array_t<int64_t>(arr);
  case py::detail::npy_api::NPY_UINT8_:
    return py::array_t<uint8_t>(arr);
  case py::detail::npy_api::NPY_UINT16_:
    return py::array_t<uint16_t>(arr);
  case py::detail::npy_api::NPY_UINT32_:
    return py::array_t<uint32_t>(arr);
  case py::detail::npy_api::NPY_UINT64_:
    return py::array_t<uint64_t>(arr);
  case py::detail::npy_api::NPY_FLOAT_:
    return py::array_t<float>(arr);
  case py::detail::npy_api::NPY_DOUBLE_:
    return py::array_t<double>(arr);
  case py::detail::npy_api::NPY_LONGDOUBLE_:
    return py::array_t<long double>(arr);
  case py::detail::npy_api::NPY_CFLOAT_:
    return py::array_t<cfloat>(arr);
  case py::detail::npy_api::NPY_CDOUBLE_:
    return py::array_t<cdouble>(arr);
  case py::detail::npy_api::NPY_CLONGDOUBLE_:
    return py::array_t<clongdouble>(arr);
  default:
    throw std::invalid_argument("Invalid data type");
  }
}

index_variants get_index(py::array &arr, const std::string &name) {
  if (arr.ndim() != 1) {
    throw std::invalid_argument(name + " array must be 1-dimensional");
  }
  const int type_num = arr.dtype().num();
  switch (type_num) {
  case py::detail::npy_api::NPY_INT32_:
    return py::array_t<int32_t>(arr);
  case py::detail::npy_api::NPY_INT64_:
    return py::array_t<int64_t>(arr);
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
ReturnState check_arrays(X x, Y y, const npy_intp n_row, const npy_intp n_col) {
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
ReturnState csr_matvec(const bool overwrite, const npy_intp n_col,
                       const npy_intp n_row, const ScalarType alpha,
                       py::array py_indptr, py::array py_indices,
                       py::array py_data, py::array py_x, py::array py_y) {

  index_variants indptr = get_array(py_indptr, "indptr");
  index_variants indices = get_array(py_indices, "indices");
  array_variants data = get_array(py_data, "data", 1);
  array_variants x = get_array(py_x, "x");
  array_variants y = get_array(py_y, "y");

  return std::visit(
      [&overwrite, &n_row, &n_col,
       &alpha](const auto &indptr, const auto &indices, const auto &data,
               const auto &y, auto &x) {
        using indptr_t = typename decltype(indptr)::value_type;
        using indices_t = typename decltype(indices)::value_type;
        using data_t = typename decltype(data)::value_type;
        using y_t = typename decltype(y)::value_type;
        using x_t = typename decltype(x)::value_type;
        using alpha_t = std::decay_t<decltype(alpha)>;
        using result_t = result_type_t<data_t, alpha_t, x_t>;

        auto return_state = check_arrays(n_col, n_row, indptr, indices, data, x, y);

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
          ssize_t x_col = x.ndim() == 1 ? 1 : x.shape(1);

          if (x_col == 1) {
            if (indices.size() < 100) {
              csr_matvec_noomp(overwrite, n_row, n_col, indptr.data(),
                               indices.data(), data.data(), alpha, x.strides(0),
                               x.data(), y.strides(0), y.mutable_data());
            } else {
              py::gil_scoped_release release;
              csr_matvec_omp(overwrite, n_row, n_col, indptr.data(),
                             indices.data(), data.data(), alpha, x.strides(0),
                             x.data(), y.strides(0), y.mutable_data());
            }

          } else {
            if (indices.size() < 100) {
              csr_matvecs_noomp(overwrite, n_row, n_col, indptr.data(),
                                indices.data(), data.data(), alpha,
                                x.strides(0), x.strides(1), x.data(),
                                y.strides(0), y.strides(1), y.mutable_data());
            } else {
              py::gil_scoped_release release;
              csr_matvecs_noomp(overwrite, n_row, n_col, indptr.data(),
                                indices.data(), data.data(), alpha,
                                x.strides(0), x.strides(1), x.data(),
                                y.strides(0), y.strides(1), y.mutable_data());
            }
          }
          return ReturnState::SUCCESS;
        }
      },
      indptr, indices, data, y, x);
}
