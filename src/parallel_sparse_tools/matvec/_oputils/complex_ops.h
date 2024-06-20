#ifndef COMPLEX_OPS_H
#define COMPLEX_OPS_H

/*
 *  Functions to handle arithmetic operations on NumPy complex values
 */

#include "result.h"

template <class c_type> class complex {

public:
  c_type real;
  c_type imag;

  complex(const c_type r = c_type(0), const c_type i = c_type(0)) {
    real = r;
    imag = i;
  }
  template <class _c_type> complex(const complex<_c_type> &B) {
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
  complex operator-() const { return complex(-real, -imag); }
  complex operator+(const complex &B) const {
    return complex(real + B.real, imag + B.imag);
  }
  complex operator-(const complex &B) const {
    return complex(real - B.real, imag - B.imag);
  }
  complex operator*(const complex &B) const {
    return complex(real * B.real - imag * B.imag,
                   real * B.imag + imag * B.real);
  }
  complex operator/(const complex &B) const {
    complex result;
    c_type denom = 1.0 / (B.real * B.real + B.imag * B.imag);
    result.real = (real * B.real + imag * B.imag) * denom;
    result.imag = (imag * B.real - real * B.imag) * denom;
    return result;
  }
  /* in-place operators */
  complex &operator+=(const complex &B) {
    real += B.real;
    imag += B.imag;
    return (*this);
  }
  complex &operator-=(const complex &B) {
    real -= B.real;
    imag -= B.imag;
    return (*this);
  }
  complex &operator*=(const complex &B) {
    c_type temp = real * B.real - imag * B.imag;
    imag = real * B.imag + imag * B.real;
    real = temp;
    return (*this);
  }
  complex &operator/=(const complex &B) {
    c_type denom = 1.0 / (B.real * B.real + B.imag * B.imag);
    c_type temp = (real * B.real + imag * B.imag) * denom;
    imag = (imag * B.real - real * B.imag) * denom;
    real = temp;
    return (*this);
  }
  /* Boolean operations */
  bool operator==(const complex &B) const {
    return real == B.real && imag == B.imag;
  }
  bool operator!=(const complex &B) const {
    return real != B.real || imag != B.imag;
  }
  bool operator<(const complex &B) const {
    return (real == B.real ? imag < B.imag : real < B.real);
  }
  bool operator>(const complex &B) const {
    return (real == B.real ? imag > B.imag : real > B.real);
  }
  bool operator<=(const complex &B) const {
    return (real == B.real ? imag <= B.imag : real <= B.real);
  }
  bool operator>=(const complex &B) const {
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
  template <class _c_type> complex &operator=(const complex<_c_type> &B) {
    real = c_type(B.real);
    imag = c_type(B.imag);
    return (*this);
  }
  template <class _c_type> complex &operator=(const _c_type &B) {
    real = c_type(B);
    imag = c_type(0);
    return (*this);
  }
};

typedef complex<float> cfloat;
typedef complex<double> cdouble;
typedef complex<long double> clongdouble;

template <class T, class U>
complex<result_type_t<T, U>> operator+(const complex<T> &A,
                                       const complex<U> &B) {
  return complex<result_type_t<T, U>>(A.real + B.real, A.imag + B.imag);
}

template <class T, class U>
complex<result_type_t<T, U>> operator+(const complex<T> &A, const U &B) {
  return complex<result_type_t<T, U>>(A.real + B, A.imag);
}

template <class T, class U>
complex<result_type_t<T, U>> operator+(const U &B, const complex<T> &A) {
  return complex<result_type_t<T, U>>(A.real + B, A.imag);
}

template <class T, class U>
complex<result_type_t<T, U>> operator-(const complex<T> &A,
                                       const complex<U> &B) {
  return complex<result_type_t<T, U>>(A.real - B.real, A.imag - B.imag);
}

template <class T, class U>
complex<result_type_t<T, U>> operator-(const complex<T> &A, const U &B) {
  return complex<result_type_t<T, U>>(A.real - B, A.imag);
}

template <class T, class U>
complex<result_type_t<T, U>> operator-(const U &B, const complex<T> &A) {
  return complex<result_type_t<T, U>>(B - A.real, -A.imag);
}

template <class T, class U>
complex<result_type_t<T, U>> operator*(const complex<T> &A,
                                       const complex<U> &B) {
  return complex<result_type_t<T, U>>(A.real * B.real - A.imag * B.imag,
                                      A.real * B.imag + A.imag * B.real);
}

template <class T, class U>
complex<result_type_t<T, U>> operator*(const complex<T> &A, const U &B) {
  return complex<result_type_t<T, U>>(A.real * B, A.imag * B);
}

template <class T, class U>
complex<result_type_t<T, U>> operator*(const U &B, const complex<T> &A) {
  return complex<result_type_t<T, U>>(A.real * B, A.imag * B);
}

template <class T, class U>
complex<result_type_t<T, U>> operator/(const complex<T> &A,
                                       const complex<U> &B) {
  return A * complex(B.real, -B.imag) / (B.real * B.real + B.imag * B.imag);
}

template <class T, class U>
complex<result_type_t<T, U>> operator/(const complex<T> &A, const U &B) {
  return complex<result_type_t<T, U>>(A.real / B, A.imag / B);
}

template <class T, class U>
complex<result_type_t<T, U>> operator/(const U &B, const complex<T> &A) {
  return B * complex(A.real, -A.imag) / (A.real * A.real + A.imag * A.imag);
}

#endif
