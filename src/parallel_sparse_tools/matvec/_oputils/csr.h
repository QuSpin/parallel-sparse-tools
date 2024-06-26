#ifndef __CSR_H
#define __CSR_H

#include "complex_ops.h"
#include "utils.h"
#include <iomanip>
#include <iostream>
#include <numpy/arrayobject.h>

// void write(const float &a) { std::cout << a; }

// void write(const double &a) { std::cout << a; }

// void write(const cfloat &a) { std::cout << a.real << std::setw(20) << a.imag;
// }

// void write(const cdouble &a) { std::cout << a.real << std::setw(20) <<
// a.imag; }

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
  const int nthread = omp_get_mdata_threads();
  std::vector<I> rco_vec(nthread);
  std::vector<T3> vco_vec(nthread);
  I *rco = &rco_vec[0];
  T3 *vco = &vco_vec[0];
#pragma omp parallel shared(indptr, indices, data, in, rco, vco, y)            \
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
  const int nthread = omp_get_mdata_threads();

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
  csr_matvecs_noomp_strided(overwrite_out, n_row, n_vecs, indptr, indices, data,
                            a, in_stride_row, in_stride_col, in, out_stride_row,
                            out_stride_col, out);
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

#endif