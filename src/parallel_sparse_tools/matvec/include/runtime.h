#ifndef __runtime_h__
#define __runtime_h__

#include "complex_ops.h"
#include <numpy/arrayobject.h>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <variant>

namespace py = pybind11;

template <typename T> class array_wrapper {
private:
  py::array arr;

public:
  typedef T value_type;

  array_wrapper(py::array &_arr) : arr(_arr) {}

  const T *data() const { return reinterpret_cast<const T *>(arr.data()); }

  T *mutable_data() { return reinterpret_cast<T *>(arr.mutable_data()); }

  ssize_t strides(int i) const { return arr.strides(i); }

  ssize_t shape(int i) const { return arr.shape(i); }

  ssize_t ndim() const { return arr.ndim(); }

  ssize_t size() const { return arr.size(); }

  bool is_c_contiguous() const {
    return (arr.flags() & py::array::c_style) != 0;
  }
};

enum class ReturnState {
  SUCCESS = 0,
  INVALID_DENSE_TYPE,
  INVALID_INDEX_TYPE,
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
  INVALID_DATA_TYPE,
  INVALID_INDPTR_NDIM,
  INVALID_INDPTR_SIZE,
  INVALID_INDICES_NDIM,
  INVALID_DATA_NDIM,
  INVALID_ALPHA_TYPE,
  INVALID_ALPHA_NDIM
};

using data_array =
    std::variant<array_wrapper<int8_t>, array_wrapper<int16_t>,
                 array_wrapper<float>, array_wrapper<double>,
                 array_wrapper<cfloat>, array_wrapper<cdouble>, ReturnState>;

using index_array =
    std::variant<array_wrapper<int32_t>, array_wrapper<int64_t>, ReturnState>;

using dense_array =
    std::variant<array_wrapper<float>, array_wrapper<double>,
                 array_wrapper<cfloat>, array_wrapper<cdouble>, ReturnState>;

using scalararrray = dense_array;

data_array get_data_array(py::array &arr) {
  const int num = arr.dtype().num();
  switch (num) {
  case py::detail::npy_api::NPY_INT8_:
    return array_wrapper<int8_t>(arr);
  case py::detail::npy_api::NPY_INT16_:
    return array_wrapper<int16_t>(arr);
  case py::detail::npy_api::NPY_FLOAT_:
    return array_wrapper<float>(arr);
  case py::detail::npy_api::NPY_DOUBLE_:
    return array_wrapper<double>(arr);
  case py::detail::npy_api::NPY_CFLOAT_:
    return array_wrapper<cfloat>(arr);
  case py::detail::npy_api::NPY_CDOUBLE_:
    return array_wrapper<cdouble>(arr);
  default:
    return ReturnState::INVALID_DATA_TYPE;
  }
}

index_array get_index_array(py::array &arr) {
  const int num = arr.dtype().num();
  switch (num) {
  case py::detail::npy_api::NPY_INT32_:
    return array_wrapper<int32_t>(arr);
  case py::detail::npy_api::NPY_INT64_:
    return array_wrapper<int64_t>(arr);
  default:
    return ReturnState::INVALID_INDEX_TYPE;
  }
}

dense_array get_dense_array(py::array &arr) {
  const int num = arr.dtype().num();
  switch (num) {
  case py::detail::npy_api::NPY_FLOAT_:
    return array_wrapper<float>(arr);
  case py::detail::npy_api::NPY_DOUBLE_:
    return array_wrapper<double>(arr);
  case py::detail::npy_api::NPY_CFLOAT_:
    return array_wrapper<cfloat>(arr);
  case py::detail::npy_api::NPY_CDOUBLE_:
    return array_wrapper<cdouble>(arr);
  default:
    return ReturnState::INVALID_DENSE_TYPE;
  }
}

template <typename in_t, typename out_t>
ReturnState check_shapes(const npy_intp n_col, const npy_intp n_row,
                         const array_wrapper<in_t> &in,
                         array_wrapper<out_t> &out) {
  const ssize_t x_row = in.shape(0);
  const ssize_t y_row = out.shape(0);
  const ssize_t x_col = in.ndim() == 1 ? 1 : in.shape(1);
  const ssize_t y_col = out.ndim() == 1 ? 1 : out.shape(1);

  if (out.ndim() > 2 || out.ndim() < 1) {
    return ReturnState::INVALID_OUT_NDIM;
  }
  if (in.ndim() > 2 || in.ndim() < 1) {
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

void define_runtime(py::module_ &m) {
  py::enum_<ReturnState>(m, "ReturnState")
      .value("SUCCESS", ReturnState::SUCCESS)
      .value("INVALID_DENSE_TYPE", ReturnState::INVALID_DENSE_TYPE)
      .value("INVALID_INDEX_TYPE", ReturnState::INVALID_INDEX_TYPE)
      .value("INVALID_N_ROW", ReturnState::INVALID_N_ROW)
      .value("INVALID_N_COL", ReturnState::INVALID_N_COL)
      .value("MISMATCH_IN_OUT_TYPES", ReturnState::MISMATCH_IN_OUT_TYPES)
      .value("MISMATCH_INDEX_TYPES", ReturnState::MISMATCH_INDEX_TYPES)
      .value("INVALID_OUT_TYPE", ReturnState::INVALID_OUT_TYPE)
      .value("INVALID_OUT_NDIM", ReturnState::INVALID_OUT_NDIM)
      .value("MISMATCH_IN_DIM", ReturnState::MISMATCH_IN_DIM)
      .value("INVALID_IN_NDIM", ReturnState::INVALID_IN_NDIM)
      .value("INVALID_IN_TYPE", ReturnState::INVALID_IN_TYPE)
      .value("MISMATCH_OUT_DIM", ReturnState::MISMATCH_OUT_DIM)
      .value("DIM_MISMATCH_IN_OUT", ReturnState::DIM_MISMATCH_IN_OUT)
      .value("INDPTR_NOT_C_CONTIGUOUS", ReturnState::INDPTR_NOT_C_CONTIGUOUS)
      .value("INVALID_INDPTR_TYPE", ReturnState::INVALID_INDPTR_TYPE)
      .value("INDICES_NOT_C_CONTIGUOUS", ReturnState::INDICES_NOT_C_CONTIGUOUS)
      .value("INVALID_INDICES_TYPE", ReturnState::INVALID_INDICES_TYPE)
      .value("DATA_NOT_C_CONTIGUOUS", ReturnState::DATA_NOT_C_CONTIGUOUS)
      .value("INVALID_DATA_TYPE", ReturnState::INVALID_DATA_TYPE)
      .value("INVALID_INDPTR_NDIM", ReturnState::INVALID_INDPTR_NDIM)
      .value("INVALID_INDPTR_SIZE", ReturnState::INVALID_INDPTR_SIZE)
      .value("INVALID_INDICES_NDIM", ReturnState::INVALID_INDICES_NDIM)
      .value("INVALID_DATA_NDIM", ReturnState::INVALID_DATA_NDIM)
      .value("INVALID_ALPHA_TYPE", ReturnState::INVALID_ALPHA_TYPE)
      .value("INVALID_ALPHA_NDIM", ReturnState::INVALID_ALPHA_NDIM);
}

#endif // __runtime_h__
