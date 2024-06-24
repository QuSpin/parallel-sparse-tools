

#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <variant>

#include "complex_ops.h"
#include "csr.h"
#include "result.h"

namespace py = pybind11;

using data_array = std::variant<py::array_t<int8_t>, py::array_t<int16_t>,
                                py::array_t<float>, py::array_t<double>,
                                py::array_t<long double>, py::array_t<cfloat>,
                                py::array_t<cdouble>, py::array_t<clongdouble>>;

using index_array = std::variant<py::array_t<int32_t>, py::array_t<int64_t>>;

using dense_array =
    std::variant<py::array_t<float>, py::array_t<double>,
                 py::array_t<long double>, py::array_t<cfloat>,
                 py::array_t<cdouble>, py::array_t<clongdouble>>;

enum class ReturnState {
  SUCCESS = 0,
  INVALID_N_ROW,
  INVALID_N_COL,
  MISMATCH_IN_OUT_TYPES,
  MISMATCH_INDEX_TYPES,
  INVALID_OUT_TYPE,
  INVALID_OUT_NDIM,
  MISMATCH_IN_DIM,
  INVALID_IN_NDIM,
  INVALID_IN_TYPE,
  MISMATCH_OUT_DIM,
  DIM_MISMATCH_IN_OUT,
  INDPTR_NOT_C_CONTIGUOUS,
  INVALID_INDPTR_TYPE,
  INDICES_NOT_C_CONTIGUOUS,
  INVALID_INDICES_TYPE,
  DATA_NOT_C_CONTIGUOUS,
  INVALID_DATA_TYPE
};

template <typename T> using result = std::variant<T, ReturnState>;

result<data_array> get_data_array(py::array &arr) {
  const int num = arr.dtype().num();
  switch (num) {
  case py::detail::npy_api::NPY_INT8_:
    return py::array_t<int8_t>(arr);
  case py::detail::npy_api::NPY_INT16_:
    return py::array_t<int16_t>(arr);
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
    return ReturnState::INVALID_DATA_TYPE;
  }
}

result<index_array> get_indptr_array(py::array &arr) {
  const int num = arr.dtype().num();
  switch (num) {
  case py::detail::npy_api::NPY_INT32_:
    return py::array_t<int32_t>(arr);
  case py::detail::npy_api::NPY_INT64_:
    return py::array_t<int64_t>(arr);
  default:
    return ReturnState::INVALID_INDPTR_TYPE;
  }
}

result<index_array> get_indices_array(py::array &arr) {
  const int num = arr.dtype().num();
  switch (num) {
  case py::detail::npy_api::NPY_INT32_:
    return py::array_t<int32_t>(arr);
  case py::detail::npy_api::NPY_INT64_:
    return py::array_t<int64_t>(arr);
  default:
    return ReturnState::INVALID_INDICES_TYPE;
  }
}

result<dense_array> get_x_array(py::array &arr) {
  const int num = arr.dtype().num();
  switch (num) {
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
    return ReturnState::INVALID_IN_TYPE;
  }
}

result<dense_array> get_y_array(py::array &arr) {
  const int num = arr.dtype().num();
  switch (num) {
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
    return ReturnState::INVALID_OUT_TYPE;
  }
}

template <typename x_t, typename y_t>
ReturnState check_shapes(const npy_intp n_col, const npy_intp n_row,
                         const py::array_t<x_t> x, py::array_t<y_t> y) {
  const ssize_t x_row = x.shape(0);
  const ssize_t y_row = y.shape(0);
  const ssize_t x_col = x.ndim() == 1 ? 1 : x.shape(1);
  const ssize_t y_col = y.ndim() == 1 ? 1 : y.shape(1);

  if (y.ndim() > 2 || y.ndim() < 1) {
    return ReturnState::INVALID_OUT_NDIM;
  }
  if (x.ndim() > 2 || x.ndim() < 1) {
    return ReturnState::INVALID_IN_NDIM;
  }
  if (n_row < 0) {
    return ReturnState::INVALID_N_ROW;
  }
  if (n_col < 0) {
    return ReturnState::INVALID_N_COL;
  }
  if (x_row != n_col) {
    return ReturnState::MISMATCH_IN_DIM;
  }
  if (y_row != n_row) {
    return ReturnState::MISMATCH_OUT_DIM;
  }
  if (y_col != x_col) {
    return ReturnState::DIM_MISMATCH_IN_OUT;
  }
  return ReturnState::SUCCESS;
}

template <typename index_t>
ReturnState check_indptr(const npy_intp n_row_or_col,
                         const py::array_t<index_t> indptr) {
  if (indptr.ndim() != 1) {
    return ReturnState::INVALID_INDPTR_NDIM;
  }
  if (indptr.size() != n_row_or_col + 1) {
    return ReturnState::INVALID_INDPTR_SIZE;
  }
  if (!indptr.ccontiguous()) {
    return ReturnState::INDPTR_NOT_C_CONTIGUOUS;
  }
  return ReturnState::SUCCESS;
}

template <typename index_t>
ReturnState check_indices(const py::array_t<index_t> indices) {
  if (indices.ndim() != 1) {
    return ReturnState::INVALID_INDICES_NDIM;
  }
  if (!indices.ccontiguous()) {
    return ReturnState::INDICES_NOT_C_CONTIGUOUS;
  }
  return ReturnState::SUCCESS;
}

template <typename data_t>
ReturnState check_data(const py::array_t<data_t> &data) {
  if (data.ndim() != 1) {
    return ReturnState::INVALID_DATA_NDIM;
  }
  if (!data.ccontiguous()) {
    return ReturnState::DATA_NOT_C_CONTIGUOUS;
  }
  return ReturnState::SUCCESS;
}

ReturnState check_indices

    template <typename index_t, typename data_t, typename x_t, typename y_t>
    ReturnState check_csr_arrays(const npy_intp n_col, const npy_intp n_row,
                                 const py::array_t<index_t> indices,
                                 const py::array_t<index_t> indptr,
                                 const py::array_t<data_t> data,
                                 const py::array_t<x_t> x, py::array_t<y_t> y) {
  auto return_state = check_shapes(n_col, n_row, x, y);
  if (return_state != ReturnState::SUCCESS) {
    return return_state;
  }

  return_state = check_indptr(n_row, indptr);
  if (return_state != ReturnState::SUCCESS) {
    return return_state;
  }

  return_state = check_indices(indices);
  if (return_state != ReturnState::SUCCESS) {
    return return_state;
  }
  return_state = check_data(data);
  if (return_state != ReturnState::SUCCESS) {
    return return_state;
  }

  return return_state;
}

template <typename ScalarType>
ReturnState csr_matvec(const bool overwrite, const npy_intp n_col,
                       const npy_intp n_row, const ScalarType alpha,
                       py::array py_indptr, py::array py_indices,
                       py::array py_data, py::array py_x, py::array py_y) {

  result<index_array> res_indptr = get_indptr_array(py_indptr);
  if (std::holds_alternative<ReturnState>(res_indptr)) {
    return std::get<ReturnState>(res_indptr);
  }
  index_array indptr = std::get<index_array>(res_indptr);

  result<index_array> res_indices = get_indices_array(py_indices);
  if (std::holds_alternative<ReturnState>(res_indices)) {
    return std::get<ReturnState>(res_indices);
  }
  index_array indices = std::get<index_array>(res_indices);

  result<data_array> res_data = get_data_array(py_data);
  if (std::holds_alternative<ReturnState>(res_data)) {
    return std::get<ReturnState>(res_data);
  }
  data_array data = std::get<data_array>(res_data);

  result<dense_array> res_x = get_x_array(py_x);
  if (std::holds_alternative<ReturnState>(res_x)) {
    return std::get<ReturnState>(res_x);
  }
  dense_array x = std::get<dense_array>(res_x);

  result<dense_array> res_y = get_y_array(py_y);
  if (std::holds_alternative<ReturnState>(res_y)) {
    return std::get<ReturnState>(res_y);
  }
  dense_array y = std::get<dense_array>(res_y);

  return std::visit(
      [&overwrite, &n_row, &n_col,
       &alpha](const auto &indptr, const auto &indices, const auto &data,
               const auto &x, auto &y) {
    using indptr_t = typename std::decay_t<decltype(indptr)>::value_type;
    using indices_t = typename std::decay_t<decltype(indices)>::value_type;
    using data_t = typename std::decay_t<decltype(data)>::value_type;
    using y_t = typename std::decay_t<decltype(y)>::value_type;
    using x_t = typename std::decay_t<decltype(x)>::value_type;
    using alpha_t = std::decay_t<decltype(alpha)>;
    using result_t = result_type_t<data_t, alpha_t, x_t>;

    if constexpr (!std::is_same_v<x_t, y_t>) {
      return ReturnState::MISMATCH_IN_OUT_TYPES;
    } else if constexpr (!std::is_same_v<x_t, result_t>) {
      return ReturnState::INVALID_OUT_TYPE;
    } else if constexpr (!std::is_same_v<indptr_t, indices_t>) {
      return ReturnState::MISMATCH_INDEX_TYPES;
    } else {
      ReturnState return_state =
          check_csr_arrays(n_col, n_row, indices, indptr, data, x, y);

      if (return_state != ReturnState::SUCCESS) {
        return return_state;
      }

      ssize_t x_col = x.ndim() == 1 ? 1 : x.shape(1);

      if (indices.size() < 100) {
        if (x_col == 1) {
          csr_matvec_noomp(overwrite, n_row, n_col, indptr.data(), indices.data(),
                         data.data(), alpha, x.strides(0), x.data(),
                         y.strides(0), y.mutable_data());
        } else {
          csr_matvecs_noomp(overwrite, n_row, n_col, x_col, indptr.data(),
                          indices.data(), data.data(), alpha, x.strides(0),
                          x.strides(1), x.data(), y.strides(0), y.strides(1),
                          y.mutable_data());
        }
      } else {
        py::gil_scoped_release release;
        if (x_col == 1) {
          csr_matvec_omp(overwrite, n_row, n_col, indptr.data(), indices.data(),
                         data.data(), alpha, x.strides(0), x.data(),
                         y.strides(0), y.mutable_data());
        } else {
          csr_matvecs_omp(overwrite, n_row, n_col, x_col, indptr.data(),
                          indices.data(), data.data(), alpha, x.strides(0),
                          x.strides(1), x.data(), y.strides(0), y.strides(1),
                          y.mutable_data());
        }
      }
    }
    return ReturnState::SUCCESS;
        }
},
      indptr, indices, data, x, y);
}

PYBIND11_MODULE(ext, m) {
  m.def("csr_matvec", &csr_matvec<int64_t>);
  m.def("csr_matvec", &csr_matvec<float>);
  m.def("csr_matvec", &csr_matvec<double>);
  m.def("csr_matvec", &csr_matvec<long double>);
  m.def("csr_matvec", &csr_matvec<cfloat>);
  m.def("csr_matvec", &csr_matvec<cdouble>);
  m.def("csr_matvec", &csr_matvec<clongdouble>);
}