#ifndef __csc_H
#define __csc_H

#include "complex_ops.h"
#include "runtime.h"
#include "utils.h"

#include <numpy/arrayobject.h>
#include <pybind11/numpy.h>

template <typename I, typename T1, typename T2, typename T3>
void csc_matvec_noomp_contig(const bool overwrite_y, const I n_row,
                             const I n_col, const I Ap[], const I Ai[],
                             const T1 Ax[], const T2 a, const T3 x[], T3 y[]) {
  if (overwrite_y) {
    for (I j = 0; j < n_row; j++) {
      y[j] = 0;
    }
  }

  for (I j = 0; j < n_col; j++) {
    I col_start = Ap[j];
    I col_end = Ap[j + 1];

    for (I ii = col_start; ii < col_end; ii++) {
      const I i = Ai[ii];
      y[i] += (a * Ax[ii]) * x[j];
    }
  }
}

template <typename I, typename T1, typename T2, typename T3>
void csc_matvec_noomp_strided(const bool overwrite_y, const I n_row,
                              const I n_col, const I Ap[], const I Ai[],
                              const T1 Ax[], const T2 a,
                              const npy_intp x_stride, const T3 x[],
                              const npy_intp y_stride, T3 y[]) {
  if (overwrite_y) {
    for (I j = 0; j < n_row; j++) {
      y[j * y_stride] = 0;
    }
  }

  for (I j = 0; j < n_col; j++) {
    I col_start = Ap[j];
    I col_end = Ap[j + 1];

    for (I ii = col_start; ii < col_end; ii++) {
      const I i = Ai[ii];
      y[i * y_stride] += (a * Ax[ii]) * x[j * x_stride];
    }
  }
}

template <typename I, typename T1, typename T2, typename T3>
void csc_matvecs_noomp_strided(
    const bool overwrite_y, const I n_row, const I n_col, const npy_intp n_vecs,
    const I Ap[],
    const I Ai[], // indices for row elements in each column
    const T1 Ax[], const T2 a,
    const npy_intp x_stride_row, // X_n_row == n_col
    const npy_intp x_stride_col, // X_n_col == n_vecs
    const T3 x[],
    const npy_intp y_stride_row, // Y_n_row == n_row
    const npy_intp y_stride_col, // Y_n_col == n_vecs
    T3 y[]) {
  if (overwrite_y) {
    for (npy_intp i = 0; i < n_row; i++) {
      for (npy_intp j = 0; j < n_vecs; j++) {
        y[i * y_stride_row + j * y_stride_col] = 0;
      }
    }
  }

  // preference ordering of 'y' as it is being written to.
  if (y_stride_col < y_stride_row) {
    for (I j = 0; j < n_col; j++) {
      I col_start = Ap[j];
      I col_end = Ap[j + 1];

      for (I ii = col_start; ii < col_end; ii++) {
        T3 *y_row = y + y_stride_row * Ai[ii];
        const T3 ax = (a * Ax[ii]);
        axpy_strided(n_vecs, ax, x_stride_col, x, y_stride_col, y_row);
      }
      x += x_stride_row;
    }
  } else {
    for (I m = 0; m < n_vecs; m++) {
      const T3 *x_row = x;
      for (I j = 0; j < n_col; j++) {
        I col_start = Ap[j];
        I col_end = Ap[j + 1];
        for (I ii = col_start; ii < col_end; ii++) {
          y[y_stride_row * Ai[ii]] += (a * Ax[ii]) * (*x_row);
        }
        x_row += x_stride_row;
      }
      x += x_stride_col;
      y += y_stride_col;
    }
  }
}

#if defined(_OPENMP)

#include "openmp.h"

template <typename I, typename T1, typename T2, typename T3>
void csc_matvec_omp_contig(const bool overwrite_y, const I n_row, const I n_col,
                           const I Ap[], const I Ai[], const T1 Ax[],
                           const T2 a, const T3 x[], T3 y[]) {
#pragma omp parallel
  {
    const int nthread = omp_get_num_threads();
    const I chunk = std::max((I)1, n_row / (100 * nthread));
    if (overwrite_y) {
#pragma omp for schedule(static)
      for (I j = 0; j < n_row; j++) {
        y[j] = 0;
      }
    }

#pragma omp for schedule(dynamic, chunk)
    for (I j = 0; j < n_col; j++) {
      I col_start = Ap[j];
      I col_end = Ap[j + 1];

      for (I ii = col_start; ii < col_end; ii++) {
        const I i = Ai[ii];
        const T3 aa = (a * Ax[ii]) * x[j];
        atomic_add(y[i], aa);
      }
    }
  }
}

template <typename I, typename T1, typename T2, typename T3>
void csc_matvec_omp_strided(const bool overwrite_y, const I n_row,
                            const I n_col, const I Ap[], const I Ai[],
                            const T1 Ax[], const T2 a, const npy_intp x_stride,
                            const T3 x[], const npy_intp y_stride, T3 y[]) {
#pragma omp parallel
  {
    const int nthread = omp_get_num_threads();
    const I chunk = std::max((I)1, n_row / (100 * nthread));
    if (overwrite_y) {
#pragma omp for schedule(static)
      for (I j = 0; j < n_row; j++) {
        y[j * y_stride] = 0;
      }
    }

#pragma omp for schedule(dynamic, chunk)
    for (I j = 0; j < n_col; j++) {
      I col_start = Ap[j];
      I col_end = Ap[j + 1];

      for (I ii = col_start; ii < col_end; ii++) {
        const I i = Ai[ii];
        const T3 aa = (a * Ax[ii]) * x[j * x_stride];
        atomic_add(y[i * y_stride], aa);
      }
    }
  }
}

template <typename I, typename T1, typename T2, typename T3>
inline void csc_matvecs_omp_strided(const bool overwrite_y, const I n_row,
                                    const I n_col, const npy_intp n_vecs,
                                    const I Ap[], const I Ai[], const T1 Ax[],
                                    const T2 a, const npy_intp x_stride_row,
                                    const npy_intp x_stride_col, const T3 x[],
                                    const npy_intp y_stride_row,
                                    const npy_intp y_stride_col, T3 y[]) {
  csc_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Ai, Ax, a,
                            x_stride_row, x_stride_col, x, y_stride_row,
                            y_stride_col, y);
}

#else

template <typename I, typename T1, typename T2, typename T3>
void csc_matvec_omp_contig(const bool overwrite_y, const I n_row, const I n_col,
                           const I Ap[], const I Ai[], const T1 Ax[],
                           const T2 a, const T3 x[], T3 y[]) {
  csc_matvec_noomp_contig(overwrite_y, n_row, n_col, Ap, Ai, Ax, a, x, y);
}

template <typename I, typename T1, typename T2, typename T3>
inline void csc_matvec_omp_strided(const bool overwrite_y, const I n_row,
                                   const I n_col, const I Ap[], const I Ai[],
                                   const T1 Ax[], const T2 a,
                                   const npy_intp x_stride, const T3 x[],
                                   const npy_intp y_stride, T3 y[]) {
  csc_matvec_noomp_strided(overwrite_y, n_row, n_col, Ap, Ai, Ax, a, x_stride,
                           x, y_stride, y);
}

template <typename I, typename T1, typename T2, typename T3>
inline void csc_matvecs_omp_strided(const bool overwrite_y, const I n_row,
                                    const I n_col, const npy_intp n_vecs,
                                    const I Ap[], const I Ai[], const T1 Ax[],
                                    const T2 a, const npy_intp x_stride_row,
                                    const npy_intp x_stride_col, const T3 x[],
                                    const npy_intp y_stride_row,
                                    const npy_intp y_stride_col, T3 y[]) {
  csc_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Ai, Ax, a,
                            x_stride_row, x_stride_col, x, y_stride_row,
                            y_stride_col, y);
}

#endif

// when openmp is not being used omp and noomp versions are identical

template <typename I, typename T1, typename T2, typename T3>
void csc_matvec_noomp(const bool overwrite_y, const I n_row, const I n_col,
                      const I Ap[], const I Aj[], const T1 Ax[], const T2 a,
                      const npy_intp x_stride_byte, const T3 x[],
                      const npy_intp y_stride_byte, T3 y[]) {
  const npy_intp y_stride = y_stride_byte / sizeof(T3);
  const npy_intp x_stride = x_stride_byte / sizeof(T3);

  if (y_stride == 1) {
    if (x_stride == 1) {
      csc_matvec_noomp_contig(overwrite_y, n_row, n_col, Ap, Aj, Ax, a, x, y);
    } else {
      csc_matvec_noomp_strided(overwrite_y, n_row, n_col, Ap, Aj, Ax, a,
                               x_stride, x, 1, y);
    }
  } else {
    if (x_stride == 1) {
      csc_matvec_noomp_strided(overwrite_y, n_row, n_col, Ap, Aj, Ax, a, 1, x,
                               y_stride, y);
    } else {
      csc_matvec_noomp_strided(overwrite_y, n_row, n_col, Ap, Aj, Ax, a,
                               x_stride, x, y_stride, y);
    }
  }
}

template <typename I, typename T1, typename T2, typename T3>
void csc_matvec_omp(const bool overwrite_y, const I n_row, const I n_col,
                    const I Ap[], const I Aj[], const T1 Ax[], const T2 a,
                    const npy_intp x_stride_byte, const T3 x[],
                    const npy_intp y_stride_byte, T3 y[]) {
  const npy_intp y_stride = y_stride_byte / sizeof(T3);
  const npy_intp x_stride = x_stride_byte / sizeof(T3);

  if (y_stride == 1) {
    if (x_stride == 1) {
      csc_matvec_omp_contig(overwrite_y, n_row, n_col, Ap, Aj, Ax, a, x, y);
    } else {
      csc_matvec_omp_strided(overwrite_y, n_row, n_col, Ap, Aj, Ax, a, x_stride,
                             x, 1, y);
    }
  } else {
    if (x_stride == 1) {
      csc_matvec_omp_strided(overwrite_y, n_row, n_col, Ap, Aj, Ax, a, 1, x,
                             y_stride, y);
    } else {
      csc_matvec_omp_strided(overwrite_y, n_row, n_col, Ap, Aj, Ax, a, x_stride,
                             x, y_stride, y);
    }
  }
}

template <typename I, typename T1, typename T2, typename T3>
inline void csc_matvecs_noomp(const bool overwrite_y, const I n_row,
                              const I n_col, const npy_intp n_vecs,
                              const I Ap[], const I Aj[], const T1 Ax[],
                              const T2 a, const npy_intp x_stride_row_byte,
                              const npy_intp x_stride_col_byte, const T3 x[],
                              const npy_intp y_stride_row_byte,
                              const npy_intp y_stride_col_byte, T3 y[]) {
  const npy_intp y_stride_row = y_stride_row_byte / sizeof(T3);
  const npy_intp y_stride_col = y_stride_col_byte / sizeof(T3);
  const npy_intp x_stride_row = x_stride_row_byte / sizeof(T3);
  const npy_intp x_stride_col = x_stride_col_byte / sizeof(T3);

  if (y_stride_col == 1) {
    if (x_stride_col == 1) {
      csc_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Aj, Ax,
                                a, x_stride_row, 1, x, y_stride_row, 1, y);
    } else if (x_stride_row == 1) {
      csc_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Aj, Ax,
                                a, 1, x_stride_col, x, y_stride_row, 1, y);
    } else {
      csc_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Aj, Ax,
                                a, x_stride_row, x_stride_col, x, y_stride_row,
                                1, y);
    }
  } else if (y_stride_row == 1) {
    if (x_stride_col == 1) {
      csc_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Aj, Ax,
                                a, x_stride_row, 1, x, 1, y_stride_col, y);
    } else if (x_stride_row == 1) {
      csc_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Aj, Ax,
                                a, 1, x_stride_col, x, 1, y_stride_col, y);
    } else {
      csc_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Aj, Ax,
                                a, x_stride_row, x_stride_col, x, 1,
                                y_stride_col, y);
    }
  } else {
    csc_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Aj, Ax, a,
                              x_stride_row, x_stride_col, x, y_stride_row,
                              y_stride_col, y);
  }
}

namespace py = pybind11;

template <typename I, typename T1, typename T2, typename T3>
inline void csc_matvecs_omp(const bool overwrite_y, const I n_row,
                            const I n_col, const npy_intp n_vecs, const I Ap[],
                            const I Aj[], const T1 Ax[], const T2 a,
                            const npy_intp x_stride_row_byte,
                            const npy_intp x_stride_col_byte, const T3 x[],
                            const npy_intp y_stride_row_byte,
                            const npy_intp y_stride_col_byte, T3 y[]) {
  const npy_intp y_stride_row = y_stride_row_byte / sizeof(T3);
  const npy_intp y_stride_col = y_stride_col_byte / sizeof(T3);
  const npy_intp x_stride_row = x_stride_row_byte / sizeof(T3);
  const npy_intp x_stride_col = x_stride_col_byte / sizeof(T3);

  if (y_stride_col == 1) {
    if (x_stride_col == 1) {
      csc_matvecs_omp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Aj, Ax, a,
                              x_stride_row, 1, x, y_stride_row, 1, y);
    } else if (x_stride_row == 1) {
      csc_matvecs_omp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Aj, Ax, a,
                              1, x_stride_col, x, y_stride_row, 1, y);
    } else {
      csc_matvecs_omp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Aj, Ax, a,
                              x_stride_row, x_stride_col, x, y_stride_row, 1,
                              y);
    }
  } else if (y_stride_row == 1) {
    if (x_stride_col == 1) {
      csc_matvecs_omp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Aj, Ax, a,
                              x_stride_row, 1, x, 1, y_stride_col, y);
    } else if (x_stride_row == 1) {
      csc_matvecs_omp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Aj, Ax, a,
                              1, x_stride_col, x, 1, y_stride_col, y);
    } else {
      csc_matvecs_omp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Aj, Ax, a,
                              x_stride_row, x_stride_col, x, 1, y_stride_col,
                              y);
    }
  } else {
    csc_matvecs_omp_strided(overwrite_y, n_row, n_col, n_vecs, Ap, Aj, Ax, a,
                            x_stride_row, x_stride_col, x, y_stride_row,
                            y_stride_col, y);
  }
}

template <typename index_t, typename data_t, typename alpha_t, typename in_t>
ReturnState check_csc_arrays(const npy_intp n_col, const npy_intp n_row,
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
  return_state = check_indptr(n_col, indptr);
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

ReturnState csc_matvec(const bool overwrite, const npy_intp n_col,
                       const npy_intp n_row, py::array py_alpha,
                       py::array py_indptr, py::array py_indices,
                       py::array py_data, py::array py_in, py::array py_out) {

  scalar_array alpha = get_scalar_array(py_alpha);
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
            ReturnState return_state = check_csc_arrays(
                n_col, n_row, indices, indptr, data, alpha, in, out);

            if (return_state != ReturnState::SUCCESS) {
              return return_state;
            }

            const ssize_t x_col = in.ndim() == 1 ? 1 : in.shape(1);

            if (n_row < 100) {
              if (x_col == 1) {
                csc_matvec_noomp(overwrite, static_cast<indptr_t>(n_row),
                                 static_cast<indptr_t>(n_col), indptr.data(),
                                 indices.data(), data.data(), *alpha.data(),
                                 in.strides(0), in.data(), out.strides(0),
                                 out.mutable_data());
              } else {
                csc_matvecs_noomp(
                    overwrite, static_cast<indptr_t>(n_row),
                    static_cast<indptr_t>(n_col), static_cast<indptr_t>(x_col),
                    indptr.data(), indices.data(), data.data(), *alpha.data(),
                    in.strides(0), in.strides(1), in.data(), out.strides(0),
                    out.strides(1), out.mutable_data());
              }
            } else {
              py::gil_scoped_release release;
              if (x_col == 1) {
                csc_matvec_omp(overwrite, static_cast<indptr_t>(n_row),
                               static_cast<indptr_t>(n_col), indptr.data(),
                               indices.data(), data.data(), *alpha.data(),
                               in.strides(0), in.data(), out.strides(0),
                               out.mutable_data());
              } else {
                csc_matvecs_omp(
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

void define_csc(py::module_ &m) {
  m.def("csc_matvec", &csc_matvec,
        "Compute the matrix-vector product for csr matrix");
}

#endif
