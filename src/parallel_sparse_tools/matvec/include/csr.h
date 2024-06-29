#ifndef __CSR_H
#define __CSR_H

#include "complex_ops.h"
#include "result.h"
#include "runtime.h"
#include "utils.h"

#include <iomanip>
#include <iostream>
#include <numpy/arrayobject.h>
#include <pybind11/numpy.h>
#include <vector>

template <class I, class T1, class T2, class T3>
void csr_matvec_noomp_contig(const bool overwrite_out, const I n_row,
                             const I indptr[], const I indices[],
                             const T1 data[], const T2 a, const T3 in[],
                             T3 out[]) {
  // const T3 a_cast = T3(a);
  if (overwrite_out) {
    for (I k = 0; k < n_row; k++) {
      T3 sum = 0;
      for (I jj = indptr[k]; jj < indptr[k + 1]; jj++) {
        sum += data[jj] * in[indices[jj]];
      }
      out[k] = a * sum;
    }
  } else {
    for (I k = 0; k < n_row; k++) {
      T3 sum = 0;
      for (I jj = indptr[k]; jj < indptr[k + 1]; jj++) {
        sum += data[jj] * in[indices[jj]];
      }

      out[k] += a * sum;
    }
  }
}

template <class I, class T1, class T2, class T3>
void csr_matvec_noomp_strided(const bool overwrite_out, const I n_row,
                              const I indptr[], const I indices[],
                              const T1 data[], const T2 a,
                              const npy_intp in_stride, const T3 in[],
                              const npy_intp out_stride, T3 out[]) {
  // const T3 a_cast = T3(a);
  if (overwrite_out) {
    for (I k = 0; k < n_row; k++) {
      T3 sum = 0;
      for (I jj = indptr[k]; jj < indptr[k + 1]; jj++) {
        sum += data[jj] * in[indices[jj] * in_stride];
      }
      out[k * out_stride] = a * sum;
    }
  } else {
    for (I k = 0; k < n_row; k++) {
      T3 sum = 0;
      for (I jj = indptr[k]; jj < indptr[k + 1]; jj++) {
        sum += data[jj] * in[indices[jj] * in_stride];
      }
      out[k * out_stride] += a * sum;
    }
  }
}

template <class I, class T1, class T2, class T3>
void csr_matvecs_noomp_strided(const bool overwrite_out, const I n_row,
                               const npy_intp n_vecs, const I indptr[],
                               const I indices[], const T1 data[], const T2 a,
                               const npy_intp in_stride_row,
                               const npy_intp in_stride_col, const T3 in[],
                               const npy_intp out_stride_row,
                               const npy_intp out_stride_col, T3 out[]) {
  if (overwrite_out) {
    for (npy_intp i = 0; i < n_row; i++) {
      for (npy_intp j = 0; j < n_vecs; j++) {
        out[i * out_stride_row + j * out_stride_col] = 0;
      }
    }
  }

  if (out_stride_col < out_stride_row) {
    for (I k = 0; k < n_row; k++) {
      for (I jj = indptr[k]; jj < indptr[k + 1]; jj++) {
        const T3 d = a * data[jj];
        const T3 *in_row = in + in_stride_row * indices[jj];
        axpy_strided(n_vecs, d, in_stride_col, in_row, out_stride_col, out);
      }
      out += out_stride_row;
    }
  } else {
    for (I m = 0; m < n_vecs; m++) {
      for (I k = 0; k < n_row; k++) {
        for (I jj = indptr[k]; jj < indptr[k + 1]; jj++) {
          const npy_intp ii = in_stride_row * indices[jj];
          (*out) += (a * data[jj]) * in[ii];
        }
        out += out_stride_row;
      }
      in += in_stride_col;
    }
  }
}

#if defined(_OPENMP)
#include "csrmv_merge.h"
#include "openmp.h"

template <class I, class T1, class T2, class T3>
inline void csr_matvec_omp_contig(const bool overwrite_out, const I n_row,
                                  const I indptr[], const I indices[],
                                  const T1 data[], const T2 a, const T3 in[],
                                  T3 out[]) {
  const int nthread = omp_get_max_threads();
  std::vector<I> rco_vec(nthread);
  std::vector<T3> vco_vec(nthread);
  I *rco = &rco_vec[0];
  T3 *vco = &vco_vec[0];
#pragma omp parallel shared(indptr, indices, data, in, rco, vco, out)          \
    firstprivate(overwrite_out, n_row)
  {
    csrmv_merge(overwrite_out, n_row, indptr, indices, data, a, in, rco, vco,
                out);
  }
}

template <class I, class T1, class T2, class T3>
inline void csr_matvec_omp_strided(const bool overwrite_out, const I n_row,
                                   const I indptr[], const I indices[],
                                   const T1 data[], const T2 a,
                                   const npy_intp in_stride, const T3 in[],
                                   const npy_intp out_stride, T3 out[]) {
  const int nthread = omp_get_max_threads();

  std::vector<I> rco_vec(nthread);
  std::vector<T3> vco_vec(nthread);
  I *rco = &rco_vec[0];
  T3 *vco = &vco_vec[0];
#pragma omp parallel
  {
    csrmv_merge_strided(overwrite_out, n_row, indptr, indices, data, a,
                        in_stride, in, rco, vco, out_stride, out);
  }
}

template <class I, class T1, class T2, class T3>
inline void csr_matvecs_omp_strided(const bool overwrite_out, const I n_row,
                                    const npy_intp n_vecs, const I indptr[],
                                    const I indices[], const T1 data[],
                                    const T2 a, const npy_intp in_stride_row,
                                    const npy_intp in_stride_col, const T3 in[],
                                    const npy_intp out_stride_row,
                                    const npy_intp out_stride_col, T3 out[]) {
  std::vector<I> rco_vec(nthread);
  std::vector<T3> vco_vec(nthread);
  I *rco = &rco_vec[0];
  T3 *vco = &vco_vec[0];
}

#else

template <class I, class T1, class T2, class T3>
inline void csr_matvec_omp_contig(const bool overwrite_out, const I n_row,
                                  const I indptr[], const I indices[],
                                  const T1 data[], const T2 a, const T3 in[],
                                  T3 out[]) {
  csr_matvec_noomp_contig(overwrite_out, n_row, indptr, indices, data, a, in,
                          out);
}

template <class I, class T1, class T2, class T3>
inline void csr_matvec_omp_strided(const bool overwrite_out, const I n_row,
                                   const I indptr[], const I indices[],
                                   const T1 data[], const T2 a,
                                   const npy_intp in_stride, const T3 in[],
                                   const npy_intp out_stride, T3 out[]) {
  csr_matvec_noomp_strided(overwrite_out, n_row, indptr, indices, data, a,
                           in_stride, in, out_stride, out);
}

template <class I, class T1, class T2, class T3>
inline void csr_matvecs_omp_strided(const bool overwrite_out, const I n_row,
                                    const npy_intp n_vecs, const I indptr[],
                                    const I indices[], const T1 data[],
                                    const T2 a, const npy_intp in_stride_row,
                                    const npy_intp in_stride_col, const T3 in[],
                                    const npy_intp out_stride_row,
                                    const npy_intp out_stride_col, T3 out[]) {
  csr_matvecs_noomp_strided(overwrite_out, n_row, n_vecs, indptr, indices, data,
                            a, in_stride_row, in_stride_col, in, out_stride_row,
                            out_stride_col, out);
}

#endif

// when openmp is not being used omp and noomp versions are identical

template <class I, class T1, class T2, class T3>
void csr_matvec_noomp(const bool overwrite_out, const I n_row, const I n_col,
                      const I indptr[], const I indices[], const T1 data[],
                      const T2 a, const npy_intp in_stride_byte, const T3 in[],
                      const npy_intp y_stride_byte, T3 out[]) {
  const npy_intp out_stride = y_stride_byte / sizeof(T3);
  const npy_intp in_stride = in_stride_byte / sizeof(T3);

  if (out_stride == 1) {
    if (in_stride == 1) {
      csr_matvec_noomp_contig(overwrite_out, n_row, indptr, indices, data, a,
                              in, out);
    } else {
      csr_matvec_noomp_strided(overwrite_out, n_row, indptr, indices, data, a,
                               in_stride, in, 1, out);
    }
  } else {
    if (in_stride == 1) {
      csr_matvec_noomp_strided(overwrite_out, n_row, indptr, indices, data, a,
                               1, in, out_stride, out);
    } else {
      csr_matvec_noomp_strided(overwrite_out, n_row, indptr, indices, data, a,
                               in_stride, in, out_stride, out);
    }
  }
}

template <class I, class T1, class T2, class T3>
void csr_matvec_omp(const bool overwrite_out, const I n_row, const I n_col,
                    const I indptr[], const I indices[], const T1 data[],
                    const T2 a, const npy_intp in_stride_byte, const T3 in[],
                    const npy_intp y_stride_byte, T3 out[]) {
  const npy_intp out_stride = y_stride_byte / sizeof(T3);
  const npy_intp in_stride = in_stride_byte / sizeof(T3);

  if (out_stride == 1) {
    if (in_stride == 1) {
      csr_matvec_omp_contig(overwrite_out, n_row, indptr, indices, data, a, in,
                            out);
    } else {
      csr_matvec_omp_strided(overwrite_out, n_row, indptr, indices, data, a,
                             in_stride, in, 1, out);
    }
  } else {
    if (in_stride == 1) {
      csr_matvec_omp_strided(overwrite_out, n_row, indptr, indices, data, a, 1,
                             in, out_stride, out);
    } else {
      csr_matvec_omp_strided(overwrite_out, n_row, indptr, indices, data, a,
                             in_stride, in, out_stride, out);
    }
  }
}

template <class I, class T1, class T2, class T3>
inline void csr_matvecs_noomp(const bool overwrite_out, const I n_row,
                              const I n_col, const npy_intp n_vecs,
                              const I indptr[], const I indices[],
                              const T1 data[], const T2 a,
                              const npy_intp in_stride_row_byte,
                              const npy_intp in_stride_col_byte, const T3 in[],
                              const npy_intp y_stride_row_byte,
                              const npy_intp y_stride_col_byte, T3 out[]) {
  const npy_intp out_stride_row = y_stride_row_byte / sizeof(T3);
  const npy_intp out_stride_col = y_stride_col_byte / sizeof(T3);
  const npy_intp in_stride_row = in_stride_row_byte / sizeof(T3);
  const npy_intp in_stride_col = in_stride_col_byte / sizeof(T3);

  if (out_stride_col == 1) {
    if (in_stride_col == 1) {
      csr_matvecs_noomp_strided(overwrite_out, n_row, n_vecs, indptr, indices,
                                data, a, in_stride_row, 1, in, out_stride_row,
                                1, out);
    } else if (in_stride_row == 1) {
      csr_matvecs_noomp_strided(overwrite_out, n_row, n_vecs, indptr, indices,
                                data, a, 1, in_stride_col, in, out_stride_row,
                                1, out);
    } else {
      csr_matvecs_noomp_strided(overwrite_out, n_row, n_vecs, indptr, indices,
                                data, a, in_stride_row, in_stride_col, in,
                                out_stride_row, 1, out);
    }
  } else if (out_stride_row == 1) {
    if (in_stride_col == 1) {
      csr_matvecs_noomp_strided(overwrite_out, n_row, n_vecs, indptr, indices,
                                data, a, in_stride_row, 1, in, 1,
                                out_stride_col, out);
    } else if (in_stride_row == 1) {
      csr_matvecs_noomp_strided(overwrite_out, n_row, n_vecs, indptr, indices,
                                data, a, 1, in_stride_col, in, 1,
                                out_stride_col, out);
    } else {
      csr_matvecs_noomp_strided(overwrite_out, n_row, n_vecs, indptr, indices,
                                data, a, in_stride_row, in_stride_col, in, 1,
                                out_stride_col, out);
    }
  } else {
    csr_matvecs_noomp_strided(overwrite_out, n_row, n_vecs, indptr, indices,
                              data, a, in_stride_row, in_stride_col, in,
                              out_stride_row, out_stride_col, out);
  }
}

template <class I, class T1, class T2, class T3>
inline void
csr_matvecs_omp(const bool overwrite_out, const I n_row, const I n_col,
                const npy_intp n_vecs, const I indptr[], const I indices[],
                const T1 data[], const T2 a, const npy_intp in_stride_row_byte,
                const npy_intp in_stride_col_byte, const T3 in[],
                const npy_intp y_stride_row_byte,
                const npy_intp y_stride_col_byte, T3 out[]) {
  const npy_intp out_stride_row = y_stride_row_byte / sizeof(T3);
  const npy_intp out_stride_col = y_stride_col_byte / sizeof(T3);
  const npy_intp in_stride_row = in_stride_row_byte / sizeof(T3);
  const npy_intp in_stride_col = in_stride_col_byte / sizeof(T3);

  if (out_stride_col == 1) {
    if (in_stride_col == 1) {
      csr_matvecs_omp_strided(overwrite_out, n_row, n_vecs, indptr, indices,
                              data, a, in_stride_row, 1, in, out_stride_row, 1,
                              out);
    } else if (in_stride_row == 1) {
      csr_matvecs_omp_strided(overwrite_out, n_row, n_vecs, indptr, indices,
                              data, a, 1, in_stride_col, in, out_stride_row, 1,
                              out);
    } else {
      csr_matvecs_omp_strided(overwrite_out, n_row, n_vecs, indptr, indices,
                              data, a, in_stride_row, in_stride_col, in,
                              out_stride_row, 1, out);
    }
  } else if (out_stride_row == 1) {
    if (in_stride_col == 1) {
      csr_matvecs_omp_strided(overwrite_out, n_row, n_vecs, indptr, indices,
                              data, a, in_stride_row, 1, in, 1, out_stride_col,
                              out);
    } else if (in_stride_row == 1) {
      csr_matvecs_omp_strided(overwrite_out, n_row, n_vecs, indptr, indices,
                              data, a, 1, in_stride_col, in, 1, out_stride_col,
                              out);
    } else {
      csr_matvecs_omp_strided(overwrite_out, n_row, n_vecs, indptr, indices,
                              data, a, in_stride_row, in_stride_col, in, 1,
                              out_stride_col, out);
    }
  } else {
    csr_matvecs_omp_strided(overwrite_out, n_row, n_vecs, indptr, indices, data,
                            a, in_stride_row, in_stride_col, in, out_stride_row,
                            out_stride_col, out);
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

scalararrray get_scalar_array(py::array &arr) {
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

            if (n_row < 100) {
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

void define_csr(py::module_ &m) {
  m.def("csr_matvec", &csr_matvec,
        "Compute the matrix-vector product for csr matrix");
}

#endif
