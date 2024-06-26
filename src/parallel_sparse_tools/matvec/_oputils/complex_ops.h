#ifndef COMPLEX_OPS_H
#define COMPLEX_OPS_H

/*
 *  Functions to handle arithmetic operations on NumPy complex_wrapper values
 */

#include "result.h"
#include <numpy/npy_common.h>

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
class complex_wrapper : public npy_complex_type<c_type> {
public:
  c_type real;
  c_type imag;

  complex_wrapper(const c_type r = c_type(0), const c_type i = c_type(0)) {
    real = r;
    imag = i;
  }
  template <class _c_type> complex_wrapper(const complex_wrapper<_c_type> &B) {
    real = B.real;
    imag = B.imag;
  }
  /* Conversion */
  operator bool() const {
    if (real == 0 && imag == 0) {
      return false;
    } else {
      return true;
    }
  }
  /* Operators */
  complex_wrapper operator-() const { return complex_wrapper(-real, -imag); }
  complex_wrapper conj() const { return complex_wrapper(real, -imag); }
  /* in-place operators */
  complex_wrapper &operator+=(const complex_wrapper &B) {
    real += B.real;
    imag += B.imag;
    return (*this);
  }
  complex_wrapper &operator-=(const complex_wrapper &B) {
    real -= B.real;
    imag -= B.imag;
    return (*this);
  }
  complex_wrapper &operator*=(const complex_wrapper &B) {
    c_type temp = real * B.real - imag * B.imag;
    imag = real * B.imag + imag * B.real;
    real = temp;
    return (*this);
  }
  complex_wrapper &operator/=(const complex_wrapper &B) {
    c_type denom = 1.0 / (B.real * B.real + B.imag * B.imag);
    c_type temp = (real * B.real + imag * B.imag) * denom;
    imag = (imag * B.real - real * B.imag) * denom;
    real = temp;
    return (*this);
  }
  /* Boolean operations */
  bool operator==(const complex_wrapper &B) const {
    return real == B.real && imag == B.imag;
  }
  bool operator!=(const complex_wrapper &B) const {
    return real != B.real || imag != B.imag;
  }
  bool operator<(const complex_wrapper &B) const {
    return (real == B.real ? imag < B.imag : real < B.real);
  }
  bool operator>(const complex_wrapper &B) const {
    return (real == B.real ? imag > B.imag : real > B.real);
  }
  bool operator<=(const complex_wrapper &B) const {
    return (real == B.real ? imag <= B.imag : real <= B.real);
  }
  bool operator>=(const complex_wrapper &B) const {
    return (real == B.real ? imag >= B.imag : real >= B.real);
  }
  template <class T> bool operator==(const T &B) const {
    return real == B && imag == T(0);
  }
  template <class T> bool operator!=(const T &B) const {
    return real != B || imag != T(0);
  }
  template <class T> bool operator<(const T &B) const {
    return (real == B ? imag < T(0) : real < B);
  }
  template <class T> bool operator>(const T &B) const {
    return (real == B ? imag > T(0) : real > B);
  }
  template <class T> bool operator<=(const T &B) const {
    return (real == B ? imag <= T(0) : real <= B);
  }
  template <class T> bool operator>=(const T &B) const {
    return (real == B ? imag >= T(0) : real >= B);
  }
  template <class _c_type>
  complex_wrapper &operator=(const complex_wrapper<_c_type> &B) {
    real = c_type(B.real());
    imag = c_type(B.imag());
    return (*this);
  }
  template <class _c_type> complex_wrapper &operator=(const _c_type &B) {
    real = c_type(B);
    imag = c_type(0);
    return (*this);
  }
};

typedef complex_wrapper<float> cfloat;
typedef complex_wrapper<double> cdouble;
typedef complex_wrapper<long double> clongdouble;

// Addition

template <class U, class T>
complex_wrapper<result_type_t<U, T>> operator+(const U &B,
                                               const complex_wrapper<T> &A) {
  return complex_wrapper(B + A.real, A.imag);
}

template <class U, class T>
complex_wrapper<result_type_t<U, T>> operator+(const complex_wrapper<T> &A,
                                               const U &B) {
  return complex_wrapper(B + A.real, A.imag);
}

template <class U, class T>
complex_wrapper<result_type_t<U, T>> operator+(const complex_wrapper<U> &B,
                                               const complex_wrapper<T> &A) {
  return complex_wrapper(B.real + A.real, B.imag + A.imag);
}

// Unary minus

template <class U, class T>
complex_wrapper<result_type_t<U, T>> operator-(const U &B,
                                               const complex_wrapper<T> &A) {
  return complex_wrapper(B - A.real, -A.imag);
}

template <class U, class T>
complex_wrapper<result_type_t<U, T>> operator-(const complex_wrapper<T> &A,
                                               const U &B) {
  return complex_wrapper(A.real - B, A.imag);
}

template <class U, class T>
complex_wrapper<result_type_t<U, T>> operator-(const complex_wrapper<U> &B,
                                               const complex_wrapper<T> &A) {
  return complex_wrapper(B.real - A.real, B.imag - A.imag);
}

// Multiplication

template <class T, class U>
complex_wrapper<result_type_t<U, T>> operator*(const U &B,
                                               const complex_wrapper<T> &A) {
  return complex_wrapper(B * A.real, B * A.imag);
}

template <class T, class U>
complex_wrapper<result_type_t<U, T>> operator*(const complex_wrapper<T> &A,
                                               const U &B) {
  return complex_wrapper(A.real * B, A.imag * B);
}

template <class T, class U>
complex_wrapper<result_type_t<U, T>> operator*(const complex_wrapper<U> &B,
                                               const complex_wrapper<T> &A) {
  return complex_wrapper(B.real * A.real - B.imag * A.imag,
                         B.imag * A.real + B.real * A.imag);
}

// Division

template <class T, class U>
complex_wrapper<result_type_t<U, T>> operator/(const U &B,
                                               const complex_wrapper<T> &A) {
  return B * A.conj() / (A.real * A.real + A.imag * A.imag);
}

template <class T, class U>
complex_wrapper<result_type_t<U, T>> operator/(const complex_wrapper<T> &A,
                                               const U &B) {
  return complex_wrapper(A.real / B, A.imag / B);
}

template <class T, class U>
complex_wrapper<result_type_t<U, T>> operator/(const complex_wrapper<U> &B,
                                               const complex_wrapper<T> &A) {
  return B * A.conj() / (A.real * A.real + A.imag * A.imag);
}

#endif
