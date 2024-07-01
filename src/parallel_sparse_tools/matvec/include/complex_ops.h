#ifndef COMPLEX_OPS_H
#define COMPLEX_OPS_H

/*
 *  Functions to handle arithmetic operations on NumPy _complex_wrapper values
 */

#include "result.h"
#include <numpy/arrayobject.h>

template <class c_type, class npy_type>
struct _complex_wrapper : public npy_type {
public:
  _complex_wrapper(const c_type r = c_type(0), const c_type i = c_type(0)) {
    npy_type::_Val[0] = r;
    npy_type::_Val[1] = i;
  }
  template <class _c_type, class _npy_type>
  _complex_wrapper(const _complex_wrapper<_c_type, _npy_type> &B) {
    npy_type::_Val[0] = B.real();
    npy_type::_Val[1] = B.imag();
  }
  /* Conversion */
  operator bool() const {
    if (npy_type::_Val[0] == 0 && npy_type::_Val[1] == 0) {
      return false;
    } else {
      return true;
    }
  }
  /* Operators */
  _complex_wrapper operator-() const {
    return _complex_wrapper(-npy_type::_Val[0], -npy_type::_Val[1]);
  }
  _complex_wrapper conj() const {
    return _complex_wrapper(npy_type::_Val[0], -npy_type::_Val[1]);
  }
  inline c_type real() const { return npy_type::_Val[0]; }
  inline c_type imag() const { return npy_type::_Val[1]; }
  /* in-place operators */
  _complex_wrapper &operator+=(const _complex_wrapper &B) {
    npy_type::_Val[0] += B.real();
    npy_type::_Val[1] += B.imag();
    return (*this);
  }
  _complex_wrapper &operator-=(const _complex_wrapper &B) {
    npy_type::_Val[0] -= B.real();
    npy_type::_Val[1] -= B.imag();
    return (*this);
  }
  _complex_wrapper &operator*=(const _complex_wrapper &B) {
    c_type temp = npy_type::_Val[0] * B.real() - npy_type::_Val[1] * B.imag();
    npy_type::_Val[1] =
        npy_type::_Val[0] * B.imag() + npy_type::_Val[1] * B.real();
    npy_type::_Val[0] = temp;
    return (*this);
  }
  _complex_wrapper &operator/=(const _complex_wrapper &B) {
    c_type denom = 1.0 / (B.real() * B.real() + B.imag() * B.imag());
    c_type temp =
        (npy_type::_Val[0] * B.real() + npy_type::_Val[1] * B.imag()) * denom;
    npy_type::_Val[1] =
        (npy_type::_Val[1] * B.real() - npy_type::_Val[0] * B.imag()) * denom;
    npy_type::_Val[0] = temp;
    return (*this);
  }
  /* Boolean operations */
  bool operator==(const _complex_wrapper &B) const {
    return npy_type::_Val[0] == B.real() && npy_type::_Val[1] == B.imag();
  }
  bool operator!=(const _complex_wrapper &B) const {
    return npy_type::_Val[0] != B.real() || npy_type::_Val[1] != B.imag();
  }
  bool operator<(const _complex_wrapper &B) const {
    return (npy_type::_Val[0] == B.real() ? npy_type::_Val[1] < B.imag()
                                          : npy_type::_Val[0] < B.real());
  }
  bool operator>(const _complex_wrapper &B) const {
    return (npy_type::_Val[0] == B.real() ? npy_type::_Val[1] > B.imag()
                                          : npy_type::_Val[0] > B.real());
  }
  bool operator<=(const _complex_wrapper &B) const {
    return (npy_type::_Val[0] == B.real() ? npy_type::_Val[1] <= B.imag()
                                          : npy_type::_Val[0] <= B.real());
  }
  bool operator>=(const _complex_wrapper &B) const {
    return (npy_type::_Val[0] == B.real() ? npy_type::_Val[1] >= B.imag()
                                          : npy_type::_Val[0] >= B.real());
  }
  template <class T> bool operator==(const T &B) const {
    return npy_type::_Val[0] == B && npy_type::_Val[1] == T(0);
  }
  template <class T> bool operator!=(const T &B) const {
    return npy_type::_Val[0] != B || npy_type::_Val[1] != T(0);
  }
  template <class T> bool operator<(const T &B) const {
    return (npy_type::_Val[0] == B ? npy_type::_Val[1] < T(0)
                                   : npy_type::_Val[0] < B);
  }
  template <class T> bool operator>(const T &B) const {
    return (npy_type::_Val[0] == B ? npy_type::_Val[1] > T(0)
                                   : npy_type::_Val[0] > B);
  }
  template <class T> bool operator<=(const T &B) const {
    return (npy_type::_Val[0] == B ? npy_type::_Val[1] <= T(0)
                                   : npy_type::_Val[0] <= B);
  }
  template <class T> bool operator>=(const T &B) const {
    return (npy_type::_Val[0] == B ? npy_type::_Val[1] >= T(0)
                                   : npy_type::_Val[0] >= B);
  }
  template <class _c_type, typename _npy_type>
  _complex_wrapper &operator=(const _complex_wrapper<_c_type, _npy_type> &B) {
    npy_type::_Val[0] = c_type(B.real());
    npy_type::_Val[1] = c_type(B.imag());
    return (*this);
  }
  template <class _c_type> _complex_wrapper &operator=(const _c_type &B) {
    npy_type::_Val[0] = c_type(B);
    npy_type::_Val[1] = c_type(0);
    return (*this);
  }
};

template <class T> struct npy_complex_type {};

template <> struct npy_complex_type<float> {
  using type = npy_cfloat;
};

template <> struct npy_complex_type<double> {
  using type = npy_cdouble;
};

template <> struct npy_complex_type<long double> {
  using type = npy_clongdouble;
};

template <class T> using npy_type_t = typename npy_complex_type<T>::type;

template <class c_type>
using complex_wrapper = _complex_wrapper<c_type, npy_type_t<c_type>>;

typedef complex_wrapper<float> cfloat;
typedef complex_wrapper<double> cdouble;
typedef complex_wrapper<long double> cldouble;

// Addition

template <class U, class T>
complex_wrapper<result_type_t<U, T>> operator+(const U &B,
                                               const complex_wrapper<T> &A) {
  return complex_wrapper<result_type_t<U, T>>(B + A.real(), A.imag());
}

template <class U, class T>
complex_wrapper<result_type_t<U, T>> operator+(const complex_wrapper<T> &A,
                                               const U &B) {
  return complex_wrapper<result_type_t<U, T>>(B + A.real(), A.imag());
}

// Unary minus

template <class U, class T>
complex_wrapper<result_type_t<U, T>> operator-(const U &B,
                                               const complex_wrapper<T> &A) {
  return complex_wrapper<result_type_t<U, T>>(B - A.real(), -A.imag());
}

template <class U, class T>
complex_wrapper<result_type_t<U, T>> operator-(const complex_wrapper<T> &A,
                                               const U &B) {
  return complex_wrapper<result_type_t<U, T>>(A.real() - B, A.imag());
}

// Multiplication

template <class T, class U>
complex_wrapper<result_type_t<U, T>> operator*(const complex_wrapper<T> &A,
                                               const U &B) {
  return complex_wrapper<result_type_t<U, T>>(A.real() * B, A.imag() * B);
}

template <class T, class U>
complex_wrapper<result_type_t<U, T>> operator*(const U &B,
                                               const complex_wrapper<T> &A) {
  return complex_wrapper<result_type_t<U, T>>(B * A.real(), B * A.imag());
}

// Division

template <class T, class U>
complex_wrapper<result_type_t<U, T>> operator/(const U &B,
                                               const complex_wrapper<T> &A) {
  return (B * A.conj()) / (A.real() * A.real() + A.imag() * A.imag());
}

template <class T, class U>
complex_wrapper<result_type_t<U, T>> operator/(const complex_wrapper<T> &A,
                                               const U &B) {
  return complex_wrapper<result_type_t<U, T>>(A.real() / B, A.imag() / B);
}

template <class U, class T>
complex_wrapper<result_type_t<U, T>> add(const complex_wrapper<U> &B,
                                         const complex_wrapper<T> &A) {
  return complex_wrapper<result_type_t<U, T>>(B.real() + A.real(),
                                              B.imag() + A.imag());
}

template <class U, class T>
complex_wrapper<result_type_t<U, T>> sub(const complex_wrapper<U> &B,
                                         const complex_wrapper<T> &A) {
  return complex_wrapper<result_type_t<U, T>>(B.real() - A.real(),
                                              B.imag() - A.imag());
}

template <class T, class U>
complex_wrapper<result_type_t<U, T>> mul(const complex_wrapper<U> &B,
                                         const complex_wrapper<T> &A) {
  return complex_wrapper<result_type_t<U, T>>(
      B.real() * A.real() - B.imag() * A.imag(),
      B.imag() * A.real() + B.real() * A.imag());
}

template <class T, class U>
complex_wrapper<result_type_t<U, T>> div(const complex_wrapper<U> &B,
                                         const complex_wrapper<T> &A) {
  return (B * A.conj()) / (A.real() * A.real() + A.imag() * A.imag());
}

cfloat operator+(const cfloat &A, const cfloat &B) { return add(B, A); }
cdouble operator+(const cfloat &A, const cdouble &B) { return add(B, A); }
cdouble operator+(const cdouble &A, const cfloat &B) { return add(B, A); }
cdouble operator+(const cdouble &A, const cdouble &B) { return add(B, A); }
cldouble operator+(const cldouble &A, const cfloat &B) { return add(B, A); }
cldouble operator+(const cfloat &A, const cldouble &B) { return add(B, A); }
cldouble operator+(const cldouble &A, const cdouble &B) { return add(B, A); }
cldouble operator+(const cdouble &A, const cldouble &B) { return add(B, A); }
cldouble operator+(const cldouble &A, const cldouble &B) { return add(B, A); }

cfloat operator-(const cfloat &A, const cfloat &B) { return sub(B, A); }
cdouble operator-(const cfloat &A, const cdouble &B) { return sub(B, A); }
cdouble operator-(const cdouble &A, const cfloat &B) { return sub(B, A); }
cdouble operator-(const cdouble &A, const cdouble &B) { return sub(B, A); }
cldouble operator-(const cldouble &A, const cfloat &B) { return sub(B, A); }
cldouble operator-(const cfloat &A, const cldouble &B) { return sub(B, A); }
cldouble operator-(const cldouble &A, const cdouble &B) { return sub(B, A); }
cldouble operator-(const cdouble &A, const cldouble &B) { return sub(B, A); }
cldouble operator-(const cldouble &A, const cldouble &B) { return sub(B, A); }

cfloat operator*(const cfloat &A, const cfloat &B) { return mul(B, A); }
cdouble operator*(const cfloat &A, const cdouble &B) { return mul(B, A); }
cdouble operator*(const cdouble &A, const cfloat &B) { return mul(B, A); }
cdouble operator*(const cdouble &A, const cdouble &B) { return mul(B, A); }
cldouble operator*(const cldouble &A, const cfloat &B) { return mul(B, A); }
cldouble operator*(const cfloat &A, const cldouble &B) { return mul(B, A); }
cldouble operator*(const cldouble &A, const cdouble &B) { return mul(B, A); }
cldouble operator*(const cdouble &A, const cldouble &B) { return mul(B, A); }
cldouble operator*(const cldouble &A, const cldouble &B) { return mul(B, A); }

cfloat operator/(const cfloat &A, const cfloat &B) { return div(B, A); }
cdouble operator/(const cfloat &A, const cdouble &B) { return div(B, A); }
cdouble operator/(const cdouble &A, const cfloat &B) { return div(B, A); }
cdouble operator/(const cdouble &A, const cdouble &B) { return div(B, A); }
cldouble operator/(const cldouble &A, const cfloat &B) { return div(B, A); }
cldouble operator/(const cfloat &A, const cldouble &B) { return div(B, A); }
cldouble operator/(const cldouble &A, const cdouble &B) { return div(B, A); }
cldouble operator/(const cdouble &A, const cldouble &B) { return div(B, A); }
cldouble operator/(const cldouble &A, const cldouble &B) { return div(B, A); }

#endif
