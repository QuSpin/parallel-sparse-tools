
#include "complex_ops.h"
#include "csr.h"
#include "result.h"

#include <iostream>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <variant>
#include <vector>

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

index_array get_indptr_array(py::array &arr) {
  const int num = arr.dtype().num();
  switch (num) {
  case py::detail::npy_api::NPY_INT32_:
    return array_wrapper<int32_t>(arr);
  case py::detail::npy_api::NPY_INT64_:
    return array_wrapper<int64_t>(arr);
  default:
    return ReturnState::INVALID_INDPTR_TYPE;
  }
}

index_array get_indices_array(py::array &arr) {
  const int num = arr.dtype().num();
  switch (num) {
  case py::detail::npy_api::NPY_INT32_:
    return array_wrapper<int32_t>(arr);
  case py::detail::npy_api::NPY_INT64_:
    return array_wrapper<int64_t>(arr);
  default:
    return ReturnState::INVALID_INDICES_TYPE;
  }
}

dense_array get_in_array(py::array &arr) {
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
    return ReturnState::INVALID_IN_TYPE;
  }
}

dense_array get_out_array(py::array &arr) {
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
    return ReturnState::INVALID_OUT_TYPE;
  }
}

scalararrray get_scalar_array(py::array &arr) {
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
    return ReturnState::INVALID_ALPHA_TYPE;
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

template <typename index_t, typename data_t, typename alpha_t, typename in_t>
ReturnState check_csr_arrays(const npy_intp n_col, const npy_intp n_row,
                             const array_wrapper<index_t> &indices,
                             const array_wrapper<index_t> &indptr,
                             const array_wrapper<data_t> &data,
                             const array_wrapper<alpha_t> &alpha,
                             const array_wrapper<in_t> &in,
                             array_wrapper<in_t> &out) {

  auto return_state = check_shapes(n_col, n_row, in, out);
  if (return_state != ReturnState::SUCCESS) {
    return return_state;
  }
  return_state = check_alpha(alpha);
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

ReturnState csr_matvec(const bool overwrite, const npy_intp n_col,
                       const npy_intp n_row, py::array py_alpha,
                       py::array py_indptr, py::array py_indices,
                       py::array py_data, py::array py_in, py::array py_out) {

  scalararrray alpha = get_scalar_array(py_alpha);
  index_array indptr = get_indptr_array(py_indptr);
  index_array indices = get_indices_array(py_indices);
  data_array data = get_data_array(py_data);
  dense_array in = get_in_array(py_in);
  dense_array out = get_out_array(py_out);

  return std::visit(
      [&overwrite, &n_row, &n_col](const auto &indptr, const auto &indices,
                                   const auto &data, const auto &alpha,
                                   const auto &in, auto &out) {
        using indptr_variant_t = std::decay_t<decltype(indptr)>;
        using indices_variant_t = std::decay_t<decltype(indices)>;
        using data_variant_t = std::decay_t<decltype(data)>;
        using alpha_variant_t = std::decay_t<decltype(alpha)>;
        using in_variant_t = std::decay_t<decltype(in)>;
        using out_variant_t = std::decay_t<decltype(out)>;

        if constexpr (std::is_same_v<indptr_variant_t, ReturnState>) {
          return indptr;
        } else if constexpr (std::is_same_v<indices_variant_t, ReturnState>) {
          return indices;
        } else if constexpr (std::is_same_v<data_variant_t, ReturnState>) {
          return data;
        } else if constexpr (std::is_same_v<alpha_variant_t, ReturnState>) {
          return alpha;
        } else if constexpr (std::is_same_v<in_variant_t, ReturnState>) {
          return in;
        } else if constexpr (std::is_same_v<out_variant_t, ReturnState>) {
          return out;
        } else {
          using indptr_t = typename indptr_variant_t::value_type;
          using indices_t = typename indices_variant_t::value_type;
          using data_t = typename data_variant_t::value_type;
          using alpha_t = typename alpha_variant_t::value_type;
          using in_t = typename in_variant_t::value_type;
          using out_t = typename out_variant_t::value_type;
          using result_t = result_type_t<data_t, alpha_t, out_t>;

          if constexpr (!std::is_same_v<out_t, in_t>) {
            return ReturnState::MISMATCH_IN_OUT_TYPES;
          } else if constexpr (!std::is_same_v<out_t, result_t>) {
            return ReturnState::INVALID_OUT_TYPE;
          } else if constexpr (!std::is_same_v<indptr_t, indices_t>) {
            return ReturnState::MISMATCH_INDEX_TYPES;
          } else {
            ReturnState return_state = check_csr_arrays(
                n_col, n_row, indices, indptr, data, alpha, in, out);

            if (return_state != ReturnState::SUCCESS) {
              return return_state;
            }

            const ssize_t x_col = in.ndim() == 1 ? 1 : in.shape(1);

            if (indices.size() < 100) {
              if (x_col == 1) {
                csr_matvec_noomp(overwrite, static_cast<indptr_t>(n_row),
                                 static_cast<indptr_t>(n_col), indptr.data(),
                                 indices.data(), data.data(), *alpha.data(),
                                 in.strides(0), in.data(), out.strides(0),
                                 out.mutable_data());
              } else {
                csr_matvecs_noomp(
                    overwrite, static_cast<indptr_t>(n_row),
                    static_cast<indptr_t>(n_col), static_cast<indptr_t>(x_col),
                    indptr.data(), indices.data(), data.data(), *alpha.data(),
                    in.strides(0), in.strides(1), in.data(), out.strides(0),
                    out.strides(1), out.mutable_data());
              }
            } else {
              py::gil_scoped_release release;
              if (x_col == 1) {
                csr_matvec_omp(overwrite, static_cast<indptr_t>(n_row),
                               static_cast<indptr_t>(n_col), indptr.data(),
                               indices.data(), data.data(), *alpha.data(),
                               in.strides(0), in.data(), out.strides(0),
                               out.mutable_data());
              } else {
                csr_matvecs_omp(
                    overwrite, static_cast<indptr_t>(n_row),
                    static_cast<indptr_t>(n_col), static_cast<indptr_t>(x_col),
                    indptr.data(), indices.data(), data.data(), *alpha.data(),
                    in.strides(0), in.strides(1), in.data(), out.strides(0),
                    out.strides(1), out.mutable_data());
              }
            }
          }
          return ReturnState::SUCCESS;
        }
      },
      indptr, indices, data, alpha, in, out);
}

PYBIND11_MODULE(_oputils, m) {

  py::enum_<ReturnState>(m, "ReturnState")
      .value("SUCCESS", ReturnState::SUCCESS)
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

  m.def("csr_matvec", &csr_matvec);
}

/**/