#ifndef __DIA_H
#define __DIA_H

#include "complex_ops.h"
#include "runtime.h"
#include "utils.h"
#include <algorithm>
#include <numpy/ndarraytypes.h>

template <typename I, typename T1, typename T2, typename T3>
void dia_matvec_noomp_contig(const bool overwrite_y, const I n_row,
                             const I n_col, const I n_diags, const I L,
                             const I offsets[], const T1 diags[], const T2 a,
                             const T3 x[], T3 y[]) {

  if (overwrite_y) {
    for (I i = 0; i < n_row; i++) {
      y[i] = 0;
    }
  }

  for (I i = 0; i < n_diags; i++) {
    const I k = offsets[i]; // diagonal offset

    const I i_start = std::max<I>(0, -k);
    const I j_start = std::max<I>(0, k);
    const I j_end = std::min<I>(std::min<I>(n_row + k, n_col), L);

    const I N = j_end - j_start; // number of elements to process

    const T1 *diag = diags + (npy_intp)i * L + j_start;
    const T3 *x_row = x + j_start;
    T3 *y_row = y + i_start;

    for (I n = 0; n < N; n++) {
      y_row[n] += (a * diag[n]) * x_row[n];
    }
  }
}

template <typename I, typename T1, typename T2, typename T3>
void dia_matvec_noomp_strided(const bool overwrite_y, const I n_row,
                              const I n_col, const I n_diags, const I L,
                              const I offsets[], const T1 diags[], const T2 a,
                              const npy_intp x_stride, const T3 x[],
                              const npy_intp y_stride, T3 y[]) {

  if (overwrite_y) {
    for (I i = 0; i < n_row; i++) {
      y[i * y_stride] = 0;
    }
  }

  for (I i = 0; i < n_diags; i++) {
    const I k = offsets[i]; // diagonal offset

    const I i_start = std::max<I>(0, -k);
    const I j_start = std::max<I>(0, k);
    const I j_end = std::min<I>(std::min<I>(n_row + k, n_col), L);

    const I N = j_end - j_start; // number of elements to process

    const T1 *diag = diags + (npy_intp)i * L + j_start;
    const T3 *x_row = x + j_start * x_stride;
    T3 *y_row = y + i_start * y_stride;

    for (I n = 0; n < N; n++) {
      y_row[n * y_stride] += (a * diag[n]) * x_row[n * x_stride];
    }
  }
}

template <typename I, typename T1, typename T2, typename T3>
void dia_matvecs_noomp_strided(
    const bool overwrite_y, const I n_row, const I n_col, const npy_intp n_vecs,
    const I n_diags, const I L, const I offsets[], const T1 diags[], const T2 a,
    const npy_intp x_stride_row, const npy_intp x_stride_col, const T3 x[],
    const npy_intp y_stride_row, const npy_intp y_stride_col, T3 y[]) {
  if (overwrite_y) {
    for (npy_intp i = 0; i < n_row; i++) {
      for (npy_intp j = 0; j < n_vecs; j++) {
        y[i * y_stride_row + j * y_stride_col] = 0;
      }
    }
  }

  if (y_stride_col < y_stride_row) {
    for (I i = 0; i < n_diags; i++) {
      const I k = offsets[i]; // diagonal offset

      const I i_start = std::max<I>(0, -k);
      const I j_start = std::max<I>(0, k);
      const I j_end = std::min<I>(std::min<I>(n_row + k, n_col), L);

      const I N = j_end - j_start; // number of elements to process

      const T1 *diag = diags + (npy_intp)i * L + j_start;
      const T3 *x_row = x + j_start * x_stride_row;
      T3 *y_row = y + i_start * y_stride_row;

      for (I n = 0; n < N; n++) {
        axpy_strided((npy_intp)n_vecs, T3(a * diag[n]), x_stride_col, x_row,
                     y_stride_col, y_row);
        x_row += x_stride_row;
        y_row += y_stride_row;
      }
    }
  } else {
    for (I i = 0; i < n_diags; i++) {
      const I k = offsets[i]; // diagonal offset

      const I i_start = std::max<I>(0, -k);
      const I j_start = std::max<I>(0, k);
      const I j_end = std::min<I>(std::min<I>(n_row + k, n_col), L);

      const I N = j_end - j_start; // number of elements to process

      const T1 *diag = diags + (npy_intp)i * L + j_start;
      const T3 *x_start = x + j_start * x_stride_row;
      T3 *y_start = y + i_start * y_stride_row;

      for (I m = 0; m < n_vecs; m++) {
        const T3 *x_row = x_start;
        T3 *y_row = y_start;

        for (I n = 0; n < N; n++) {
          (*y_row) += (a * diag[n]) * (*x_row);
          x_row += x_stride_row;
          y_row += y_stride_row;
        }

        y_start += y_stride_col;
        x_start += x_stride_col;
      }
    }
  }
}

#if defined(_OPENMP)
#include "csrmv_merge.h"
#include "openmp.h"

template <typename I, typename T1, typename T2, typename T3>
void dia_matvec_omp_contig(const bool overwrite_y, const I n_row, const I n_col,
                           const I n_diags, const I L, const I offsets[],
                           const T1 diags[], const T2 a, const T3 x[], T3 y[]) {
#pragma omp parallel
  {
    if (overwrite_y) {
#pragma omp for schedule(static)
      for (I n = 0; n < n_row; n++) {
        y[n] = 0;
      }
    }

    for (I i = 0; i < n_diags; i++) {
      const I k = offsets[i]; // diagonal offset

      const I i_start = std::max<I>(0, -k);
      const I j_start = std::max<I>(0, k);
      const I j_end = std::min<I>(std::min<I>(n_row + k, n_col), L);

      const I N = j_end - j_start; // number of elements to process
      const T1 *diag = diags + i * L + j_start;
      const T3 *x_row = x + j_start;
      T3 *y_row = y + i_start;

#pragma omp for schedule(static)
      for (I n = 0; n < N; n++) {
        y_row[n] += (a * diag[n]) * x_row[n];
      }
    }
  }
}

template <typename I, typename T1, typename T2, typename T3>
void dia_matvec_omp_strided(const bool overwrite_y, const I n_row,
                            const I n_col, const I n_diags, const I L,
                            const I offsets[], const T1 diags[], const T2 a,
                            const npy_intp x_stride, const T3 x[],
                            const npy_intp y_stride, T3 y[]) {
#pragma omp parallel
  {
    if (overwrite_y) {
#pragma omp for schedule(static)
      for (I n = 0; n < n_row; n++) {
        y[n * y_stride] = 0;
      }
    }

    for (I i = 0; i < n_diags; i++) {
      const I k = offsets[i]; // diagonal offset

      const I i_start = std::max<I>(0, -k);
      const I j_start = std::max<I>(0, k);
      const I j_end = std::min<I>(std::min<I>(n_row + k, n_col), L);

      const I N = j_end - j_start; // number of elements to process
      const T1 *diag = diags + i * L + j_start;
      const T3 *x_row = x + j_start * x_stride;
      T3 *y_row = y + i_start * y_stride;

#pragma omp for schedule(static)
      for (I n = 0; n < N; n++) {
        y_row[n * y_stride] += (a * diag[n]) * x_row[n * x_stride];
      }
    }
  }
}

template <typename I, typename T1, typename T2, typename T3>
inline void dia_matvecs_omp_strided(
    const bool overwrite_y, const I n_row, const I n_col, const npy_intp n_vecs,
    const I n_diags, const I L, const I offsets[], const T1 diags[], const T2 a,
    const npy_intp x_stride_row, const npy_intp x_stride_col, const T3 x[],
    const npy_intp y_stride_row, const npy_intp y_stride_col, T3 y[]) {
  dia_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                            offsets, diags, a, x_stride_row, x_stride_col, x,
                            y_stride_row, y_stride_col, y);
}

#else

template <typename I, typename T1, typename T2, typename T3>
inline void dia_matvec_omp_contig(const bool overwrite_y, const I n_row,
                                  const I n_col, const I n_diags, const I L,
                                  const I offsets[], const T1 diags[],
                                  const T2 a, const T3 x[], T3 y[]) {
  dia_matvec_noomp_contig(overwrite_y, n_row, n_col, n_diags, L, offsets, diags,
                          a, x, y);
}

template <typename I, typename T1, typename T2, typename T3>
inline void
dia_matvec_omp_strided(const bool overwrite_y, const I n_row, const I n_col,
                       const I n_diags, const I L, const I offsets[],
                       const T1 diags[], const T2 a, const npy_intp x_stride,
                       const T3 x[], const npy_intp y_stride, T3 y[]) {
  dia_matvec_noomp_strided(overwrite_y, n_row, n_col, n_diags, L, offsets,
                           diags, a, x_stride, x, y_stride, y);
}

template <typename I, typename T1, typename T2, typename T3>
inline void dia_matvecs_omp_strided(
    const bool overwrite_y, const I n_row, const I n_col, const npy_intp n_vecs,
    const I n_diags, const I L, const I offsets[], const T1 diags[], const T2 a,
    const npy_intp x_stride_row, const npy_intp x_stride_col, const T3 x[],
    const npy_intp y_stride_row, const npy_intp y_stride_col, T3 y[]) {
  dia_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                            offsets, diags, a, x_stride_row, x_stride_col, x,
                            y_stride_row, y_stride_col, y);
}

#endif

template <typename I, typename T1, typename T2, typename T3>
void dia_matvec_omp(const bool overwrite_y, const I n_row, const I n_col,
                    const I n_diags, const I L, const I offsets[],
                    const T1 diags[], const T2 a, const npy_intp x_stride_bytes,
                    const T3 x[], const npy_intp y_stride_bytes, T3 y[]) {
  const npy_intp x_stride = x_stride_bytes / sizeof(T3);
  const npy_intp y_stride = y_stride_bytes / sizeof(T3);
  if (y_stride == 1) {
    if (x_stride == 1) {
      dia_matvec_omp_contig(overwrite_y, n_row, n_col, n_diags, L, offsets,
                            diags, a, x, y);
    } else {
      dia_matvec_omp_strided(overwrite_y, n_row, n_col, n_diags, L, offsets,
                             diags, a, x_stride, x, 1, y);
    }
  } else {
    if (x_stride == 1) {
      dia_matvec_omp_strided(overwrite_y, n_row, n_col, n_diags, L, offsets,
                             diags, a, 1, x, y_stride, y);
    } else {
      dia_matvec_omp_strided(overwrite_y, n_row, n_col, n_diags, L, offsets,
                             diags, a, x_stride, x, y_stride, y);
    }
  }
}

template <typename I, typename T1, typename T2, typename T3>
void dia_matvec_noomp(const bool overwrite_y, const I n_row, const I n_col,
                      const I n_diags, const I L, const I offsets[],
                      const T1 diags[], const T2 a,
                      const npy_intp x_stride_bytes, const T3 x[],
                      const npy_intp y_stride_bytes, T3 y[]) {
  const npy_intp x_stride = x_stride_bytes / sizeof(T3);
  const npy_intp y_stride = y_stride_bytes / sizeof(T3);
  if (y_stride == 1) {
    if (x_stride == 1) {
      dia_matvec_noomp_contig(overwrite_y, n_row, n_col, n_diags, L, offsets,
                              diags, a, x, y);
    } else {
      dia_matvec_noomp_strided(overwrite_y, n_row, n_col, n_diags, L, offsets,
                               diags, a, x_stride, x, 1, y);
    }
  } else {
    if (x_stride == 1) {
      dia_matvec_noomp_strided(overwrite_y, n_row, n_col, n_diags, L, offsets,
                               diags, a, 1, x, y_stride, y);
    } else {
      dia_matvec_noomp_strided(overwrite_y, n_row, n_col, n_diags, L, offsets,
                               diags, a, x_stride, x, y_stride, y);
    }
  }
}

template <typename I, typename T1, typename T2, typename T3>
inline void dia_matvecs_omp(const bool overwrite_y, const I n_row,
                            const I n_col, const npy_intp n_vecs,
                            const I n_diags, const I L, const I offsets[],
                            const T1 diags[], const T2 a,
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
      dia_matvecs_omp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                              offsets, diags, a, x_stride_row, 1, x,
                              y_stride_row, 1, y);
    } else if (x_stride_row == 1) {
      dia_matvecs_omp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                              offsets, diags, a, 1, x_stride_col, x,
                              y_stride_row, 1, y);
    } else {
      dia_matvecs_omp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                              offsets, diags, a, x_stride_row, x_stride_col, x,
                              y_stride_row, 1, y);
    }
  } else if (y_stride_row == 1) {
    if (x_stride_col == 1) {
      dia_matvecs_omp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                              offsets, diags, a, x_stride_row, 1, x, 1,
                              y_stride_col, y);
    } else if (x_stride_row == 1) {
      dia_matvecs_omp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                              offsets, diags, a, 1, x_stride_col, x, 1,
                              y_stride_col, y);
    } else {
      dia_matvecs_omp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                              offsets, diags, a, x_stride_row, x_stride_col, x,
                              1, y_stride_col, y);
    }
  } else {
    dia_matvecs_omp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                            offsets, diags, a, x_stride_row, x_stride_col, x,
                            y_stride_row, y_stride_col, y);
  }
}

template <typename I, typename T1, typename T2, typename T3>
inline void dia_matvecs_noomp(const bool overwrite_y, const I n_row,
                              const I n_col, const npy_intp n_vecs,
                              const I n_diags, const I L, const I offsets[],
                              const T1 diags[], const T2 a,
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
      dia_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                                offsets, diags, a, x_stride_row, 1, x,
                                y_stride_row, 1, y);
    } else if (x_stride_row == 1) {
      dia_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                                offsets, diags, a, 1, x_stride_col, x,
                                y_stride_row, 1, y);
    } else {
      dia_matvecs_omp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                              offsets, diags, a, x_stride_row, x_stride_col, x,
                              y_stride_row, 1, y);
    }
  } else if (y_stride_row == 1) {
    if (x_stride_col == 1) {
      dia_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                                offsets, diags, a, x_stride_row, 1, x, 1,
                                y_stride_col, y);
    } else if (x_stride_row == 1) {
      dia_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                                offsets, diags, a, 1, x_stride_col, x, 1,
                                y_stride_col, y);
    } else {
      dia_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                                offsets, diags, a, x_stride_row, x_stride_col,
                                x, 1, y_stride_col, y);
    }
  } else {
    dia_matvecs_noomp_strided(overwrite_y, n_row, n_col, n_vecs, n_diags, L,
                              offsets, diags, a, x_stride_row, x_stride_col, x,
                              y_stride_row, y_stride_col, y);
  }
}

data_array get_diags_array(py::array &arr) {
  data_array result = get_data_array(arr);
  return (std::holds_alternative<ReturnState>(result)
              ? ReturnState::INVALID_DIAGS_TYPE
              : result);
}

index_array get_offsets_array(py::array &arr) {
  index_array result = get_index_array(arr);
  return (std::holds_alternative<ReturnState>(result)
              ? ReturnState::INVALID_OFFSETS_TYPE
              : result);
}

template <typename offsets_t>
ReturnState check_offsets(const array_wrapper<offsets_t> &offsets) {
  if (!offsets.is_c_contiguous()) {
    return ReturnState::OFFSETS_NOT_C_CONTIGUOUS;
  }
  if (offsets.ndim() != 1) {
    return ReturnState::INVALID_OFFSETS_NDIM;
  }
  return ReturnState::SUCCESS;
}

template <typename diags_t>
ReturnState check_diags(const ssize_t n_offsets,
                        const array_wrapper<diags_t> &diags) {
  if (!diags.is_c_contiguous()) {
    return ReturnState::DIAGS_NOT_C_CONTIGUOUS;
  }
  if (diags.ndim() != 2) {
    return ReturnState::INVALID_DIAGS_NDIM;
  }
  if (diags.shape(0) != n_offsets) {
    return ReturnState::MISMATCH_DIAGS_OFFSETS;
  }
  return ReturnState::SUCCESS;
}

template <typename offsets_t, typename diags_t, typename alpha_t, typename in_t>
ReturnState check_dia_arrays(const npy_intp n_col, const npy_intp n_row,
                             const array_wrapper<offsets_t> &offsets,
                             const array_wrapper<diags_t> &diags,
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
  return_state = check_offsets(offsets);
  if (return_state != ReturnState::SUCCESS) {
    return return_state;
  }
  return_state = check_diags(offsets.size(), diags);
  if (return_state != ReturnState::SUCCESS) {
    return return_state;
  }
  return return_state;
}

ReturnState dia_matvec(const bool overwrite, const npy_intp n_col,
                       const npy_intp n_row, py::array py_alpha,
                       py::array py_offsets, py::array py_diags,
                       py::array py_in, py::array py_out) {

  scalar_array alpha = get_scalar_array(py_alpha);
  index_array offsets = get_offsets_array(py_offsets);
  data_array diags = get_diags_array(py_diags);
  dense_array in = get_in_array(py_in);
  dense_array out = get_out_array(py_out);

  return std::visit(
      [&overwrite, &n_row, &n_col](const auto &offsets, const auto &diags,
                                   const auto &alpha, const auto &in,
                                   auto &out) {
        using offsets_variant_t = std::decay_t<decltype(offsets)>;
        using diags_variant_t = std::decay_t<decltype(diags)>;
        using alpha_variant_t = std::decay_t<decltype(alpha)>;
        using in_variant_t = std::decay_t<decltype(in)>;
        using out_variant_t = std::decay_t<decltype(out)>;

        if constexpr (std::is_same_v<offsets_variant_t, ReturnState>) {
          return offsets;
        } else if constexpr (std::is_same_v<diags_variant_t, ReturnState>) {
          return diags;
        } else if constexpr (std::is_same_v<alpha_variant_t, ReturnState>) {
          return alpha;
        } else if constexpr (std::is_same_v<in_variant_t, ReturnState>) {
          return in;
        } else if constexpr (std::is_same_v<out_variant_t, ReturnState>) {
          return out;
        } else {
          using offsets_t = typename offsets_variant_t::value_type;
          using diags_t = typename diags_variant_t::value_type;
          using alpha_t = typename alpha_variant_t::value_type;
          using in_t = typename in_variant_t::value_type;
          using out_t = typename out_variant_t::value_type;
          using result_t = result_type_t<diags_t, alpha_t, out_t>;

          if constexpr (!std::is_same_v<out_t, in_t>) {
            return ReturnState::MISMATCH_IN_OUT_TYPES;
          } else if constexpr (!std::is_same_v<out_t, result_t>) {
            return ReturnState::INVALID_OUT_TYPE;
          } else {
            ReturnState return_state =
                check_dia_arrays(n_col, n_row, offsets, diags, alpha, in, out);

            if (return_state != ReturnState::SUCCESS) {
              return return_state;
            }

            const ssize_t x_col = in.ndim() == 1 ? 1 : in.shape(1);
            const ssize_t n_diags = offsets.size();
            const ssize_t L = diags.shape(1);

            if (n_row < 100) {
              if (x_col == 1) {
                dia_matvec_noomp(overwrite, static_cast<offsets_t>(n_row),
                                 static_cast<offsets_t>(n_col),
                                 static_cast<offsets_t>(n_diags),
                                 static_cast<offsets_t>(L), offsets.data(),
                                 diags.data(), *alpha.data(), in.strides(0),
                                 in.data(), out.strides(0), out.mutable_data());
              } else {
                dia_matvecs_noomp(overwrite, static_cast<offsets_t>(n_row),
                                  static_cast<offsets_t>(n_col),
                                  static_cast<offsets_t>(x_col),
                                  static_cast<offsets_t>(n_diags),
                                  static_cast<offsets_t>(L), offsets.data(),
                                  diags.data(), *alpha.data(), in.strides(0),
                                  in.strides(1), in.data(), out.strides(0),
                                  out.strides(1), out.mutable_data());
              }
            } else {
              py::gil_scoped_release release;
              if (x_col == 1) {
                dia_matvec_omp(overwrite, static_cast<offsets_t>(n_row),
                               static_cast<offsets_t>(n_col),
                               static_cast<offsets_t>(n_diags),
                               static_cast<offsets_t>(L), offsets.data(),
                               diags.data(), *alpha.data(), in.strides(0),
                               in.data(), out.strides(0), out.mutable_data());
              } else {
                dia_matvecs_omp(overwrite, static_cast<offsets_t>(n_row),
                                static_cast<offsets_t>(n_col),
                                static_cast<offsets_t>(x_col),
                                static_cast<offsets_t>(n_diags),
                                static_cast<offsets_t>(L), offsets.data(),
                                diags.data(), *alpha.data(), in.strides(0),
                                in.strides(1), in.data(), out.strides(0),
                                out.strides(1), out.mutable_data());
              }
            }
          }
          return ReturnState::SUCCESS;
        }
      },
      offsets, diags, alpha, in, out);
}

void define_dia(py::module_ &m) {
  m.def("dia_matvec", &dia_matvec,
        "Compute the matrix-vector product for dia matrix");
}

#endif
