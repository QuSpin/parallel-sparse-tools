#ifndef __UTILS_H
#define __UTILS_H

#include "complex_ops.h"
#include "runtime.h"

#include <numpy/arrayobject.h>
#include <pybind11/numpy.h>

// y += a*x
template <typename I, typename T>
void axpy_strided(const I n, const T a, const I x_stride, const T *x,
                  const I y_stride, T *y) {
  for (I i = 0; i < n; ++i) {
    (*y) += a * (*x);
    y += y_stride;
    x += x_stride;
  }
}

// y += a*x
template <typename I, typename T>
void axpy_contig(const I n, const T a, const I x_stride, const T *x,
                 const I y_stride, T *y) {
  for (I i = 0; i < n; ++i) {
    (*y++) += a * (*x++);
  }
}

index_array get_indices_array(py::array &arr) {
  index_array result = get_index_array(arr);
  return (std::holds_alternative<ReturnState>(result)
              ? ReturnState::INVALID_INDICES_TYPE
              : result);
}

index_array get_indptr_array(py::array &arr) {
  index_array result = get_index_array(arr);
  return (std::holds_alternative<ReturnState>(result)
              ? ReturnState::INVALID_INDPTR_TYPE
              : result);
}

dense_array get_in_array(py::array &arr) {
  dense_array result = get_dense_array(arr);
  return (std::holds_alternative<ReturnState>(result)
              ? ReturnState::INVALID_IN_TYPE
              : result);
}

dense_array get_out_array(py::array &arr) {
  dense_array result = get_dense_array(arr);
  return (std::holds_alternative<ReturnState>(result)
              ? ReturnState::INVALID_OUT_TYPE
              : result);
}

scalar_array get_scalar_array(py::array &arr) {
  dense_array result = get_dense_array(arr);
  return (std::holds_alternative<ReturnState>(result)
              ? ReturnState::INVALID_ALPHA_TYPE
              : result);
}

template <typename index_t>
ReturnState check_indptr(const npy_intp n_row_or_col,
                         const array_wrapper<index_t> &indptr) {
  if (indptr.ndim() != 1) {
    return ReturnState::INVALID_INDPTR_NDIM;
  }
  if (indptr.size() != n_row_or_col + 1) {
    return ReturnState::INVALID_INDPTR_SIZE;
  }
  if (!indptr.is_c_contiguous()) {
    return ReturnState::INDPTR_NOT_C_CONTIGUOUS;
  }
  return ReturnState::SUCCESS;
}

template <typename index_t>
ReturnState check_indices(const array_wrapper<index_t> &indices) {
  if (indices.ndim() != 1) {
    return ReturnState::INVALID_INDICES_NDIM;
  }
  if (!indices.is_c_contiguous()) {
    return ReturnState::INDICES_NOT_C_CONTIGUOUS;
  }
  return ReturnState::SUCCESS;
}

template <typename data_t>
ReturnState check_data(const array_wrapper<data_t> &data) {
  if (data.ndim() != 1) {
    return ReturnState::INVALID_DATA_NDIM;
  }
  if (!data.is_c_contiguous()) {
    return ReturnState::DATA_NOT_C_CONTIGUOUS;
  }
  return ReturnState::SUCCESS;
}

template <typename alpha_t>
ReturnState check_alpha(const array_wrapper<alpha_t> &alpha) {
  if (alpha.ndim() != 0) {
    return ReturnState::INVALID_ALPHA_NDIM;
  }
  return ReturnState::SUCCESS;
}

#endif
