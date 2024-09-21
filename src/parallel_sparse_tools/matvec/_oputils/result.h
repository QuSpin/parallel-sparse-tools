#pragma once

#include <complex>
#include <type_traits>
#include <cstdint>


typedef std::complex<float> cfloat;
typedef std::complex<double> cdouble;
typedef std::complex<long double> cldouble;

template <typename T, typename... Ts> struct result_type {
  using value_type = result_type<T, typename result_type<Ts...>::value_type>;
};

// base case:
template <typename T> struct result_type<T> {
  using value_type = T;
};

// helper to get the value_type from the result_type if not specialized:
template <typename lhs, typename rhs> struct result_type<lhs, rhs> {
  using value_type =
      std::decay_t<decltype(std::declval<lhs>() + std::declval<rhs>())>;
};

// interface:
template <typename... T>
using result_type_t = typename result_type<T...>::value_type;

// numpy-like type promotion rules:
template <> struct result_type<int8_t, int8_t> {
  using value_type = int8_t;
};
template <> struct result_type<int8_t, uint8_t> {
  using value_type = int16_t;
};
template <> struct result_type<int8_t, int16_t> {
  using value_type = int16_t;
};
template <> struct result_type<int8_t, uint16_t> {
  using value_type = int32_t;
};
template <> struct result_type<int8_t, int32_t> {
  using value_type = int32_t;
};
template <> struct result_type<int8_t, uint32_t> {
  using value_type = int64_t;
};
template <> struct result_type<int8_t, int64_t> {
  using value_type = int64_t;
};
template <> struct result_type<int8_t, uint64_t> {
  using value_type = double;
};
template <> struct result_type<int8_t, float> {
  using value_type = float;
};
template <> struct result_type<int8_t, double> {
  using value_type = double;
};
template <> struct result_type<int8_t, cfloat> {
  using value_type = cfloat;
};
template <> struct result_type<int8_t, cdouble> {
  using value_type = cdouble;
};
template <> struct result_type<uint8_t, int8_t> {
  using value_type = int16_t;
};
template <> struct result_type<uint8_t, uint8_t> {
  using value_type = uint8_t;
};
template <> struct result_type<uint8_t, int16_t> {
  using value_type = int16_t;
};
template <> struct result_type<uint8_t, uint16_t> {
  using value_type = uint16_t;
};
template <> struct result_type<uint8_t, int32_t> {
  using value_type = int32_t;
};
template <> struct result_type<uint8_t, uint32_t> {
  using value_type = uint32_t;
};
template <> struct result_type<uint8_t, int64_t> {
  using value_type = int64_t;
};
template <> struct result_type<uint8_t, uint64_t> {
  using value_type = uint64_t;
};
template <> struct result_type<uint8_t, float> {
  using value_type = float;
};
template <> struct result_type<uint8_t, double> {
  using value_type = double;
};
template <> struct result_type<uint8_t, cfloat> {
  using value_type = cfloat;
};
template <> struct result_type<uint8_t, cdouble> {
  using value_type = cdouble;
};
template <> struct result_type<int16_t, int8_t> {
  using value_type = int16_t;
};
template <> struct result_type<int16_t, uint8_t> {
  using value_type = int16_t;
};
template <> struct result_type<int16_t, int16_t> {
  using value_type = int16_t;
};
template <> struct result_type<int16_t, uint16_t> {
  using value_type = int32_t;
};
template <> struct result_type<int16_t, int32_t> {
  using value_type = int32_t;
};
template <> struct result_type<int16_t, uint32_t> {
  using value_type = int64_t;
};
template <> struct result_type<int16_t, int64_t> {
  using value_type = int64_t;
};
template <> struct result_type<int16_t, uint64_t> {
  using value_type = double;
};
template <> struct result_type<int16_t, float> {
  using value_type = float;
};
template <> struct result_type<int16_t, double> {
  using value_type = double;
};
template <> struct result_type<int16_t, cfloat> {
  using value_type = cfloat;
};
template <> struct result_type<int16_t, cdouble> {
  using value_type = cdouble;
};
template <> struct result_type<uint16_t, int8_t> {
  using value_type = int32_t;
};
template <> struct result_type<uint16_t, uint8_t> {
  using value_type = uint16_t;
};
template <> struct result_type<uint16_t, int16_t> {
  using value_type = int32_t;
};
template <> struct result_type<uint16_t, uint16_t> {
  using value_type = uint16_t;
};
template <> struct result_type<uint16_t, int32_t> {
  using value_type = int32_t;
};
template <> struct result_type<uint16_t, uint32_t> {
  using value_type = uint32_t;
};
template <> struct result_type<uint16_t, int64_t> {
  using value_type = int64_t;
};
template <> struct result_type<uint16_t, uint64_t> {
  using value_type = uint64_t;
};
template <> struct result_type<uint16_t, float> {
  using value_type = float;
};
template <> struct result_type<uint16_t, double> {
  using value_type = double;
};
template <> struct result_type<uint16_t, cfloat> {
  using value_type = cfloat;
};
template <> struct result_type<uint16_t, cdouble> {
  using value_type = cdouble;
};
template <> struct result_type<int32_t, int8_t> {
  using value_type = int32_t;
};
template <> struct result_type<int32_t, uint8_t> {
  using value_type = int32_t;
};
template <> struct result_type<int32_t, int16_t> {
  using value_type = int32_t;
};
template <> struct result_type<int32_t, uint16_t> {
  using value_type = int32_t;
};
template <> struct result_type<int32_t, int32_t> {
  using value_type = int32_t;
};
template <> struct result_type<int32_t, uint32_t> {
  using value_type = int64_t;
};
template <> struct result_type<int32_t, int64_t> {
  using value_type = int64_t;
};
template <> struct result_type<int32_t, uint64_t> {
  using value_type = double;
};
template <> struct result_type<int32_t, float> {
  using value_type = double;
};
template <> struct result_type<int32_t, double> {
  using value_type = double;
};
template <> struct result_type<int32_t, cfloat> {
  using value_type = cdouble;
};
template <> struct result_type<int32_t, cdouble> {
  using value_type = cdouble;
};
template <> struct result_type<uint32_t, int8_t> {
  using value_type = int64_t;
};
template <> struct result_type<uint32_t, uint8_t> {
  using value_type = uint32_t;
};
template <> struct result_type<uint32_t, int16_t> {
  using value_type = int64_t;
};
template <> struct result_type<uint32_t, uint16_t> {
  using value_type = uint32_t;
};
template <> struct result_type<uint32_t, int32_t> {
  using value_type = int64_t;
};
template <> struct result_type<uint32_t, uint32_t> {
  using value_type = uint32_t;
};
template <> struct result_type<uint32_t, int64_t> {
  using value_type = int64_t;
};
template <> struct result_type<uint32_t, uint64_t> {
  using value_type = uint64_t;
};
template <> struct result_type<uint32_t, float> {
  using value_type = double;
};
template <> struct result_type<uint32_t, double> {
  using value_type = double;
};
template <> struct result_type<uint32_t, cfloat> {
  using value_type = cdouble;
};
template <> struct result_type<uint32_t, cdouble> {
  using value_type = cdouble;
};
template <> struct result_type<int64_t, int8_t> {
  using value_type = int64_t;
};
template <> struct result_type<int64_t, uint8_t> {
  using value_type = int64_t;
};
template <> struct result_type<int64_t, int16_t> {
  using value_type = int64_t;
};
template <> struct result_type<int64_t, uint16_t> {
  using value_type = int64_t;
};
template <> struct result_type<int64_t, int32_t> {
  using value_type = int64_t;
};
template <> struct result_type<int64_t, uint32_t> {
  using value_type = int64_t;
};
template <> struct result_type<int64_t, int64_t> {
  using value_type = int64_t;
};
template <> struct result_type<int64_t, uint64_t> {
  using value_type = double;
};
template <> struct result_type<int64_t, float> {
  using value_type = double;
};
template <> struct result_type<int64_t, double> {
  using value_type = double;
};
template <> struct result_type<int64_t, cfloat> {
  using value_type = cdouble;
};
template <> struct result_type<int64_t, cdouble> {
  using value_type = cdouble;
};
template <> struct result_type<uint64_t, int8_t> {
  using value_type = double;
};
template <> struct result_type<uint64_t, uint8_t> {
  using value_type = uint64_t;
};
template <> struct result_type<uint64_t, int16_t> {
  using value_type = double;
};
template <> struct result_type<uint64_t, uint16_t> {
  using value_type = uint64_t;
};
template <> struct result_type<uint64_t, int32_t> {
  using value_type = double;
};
template <> struct result_type<uint64_t, uint32_t> {
  using value_type = uint64_t;
};
template <> struct result_type<uint64_t, int64_t> {
  using value_type = double;
};
template <> struct result_type<uint64_t, uint64_t> {
  using value_type = uint64_t;
};
template <> struct result_type<uint64_t, float> {
  using value_type = double;
};
template <> struct result_type<uint64_t, double> {
  using value_type = double;
};
template <> struct result_type<uint64_t, cfloat> {
  using value_type = cdouble;
};
template <> struct result_type<uint64_t, cdouble> {
  using value_type = cdouble;
};
template <> struct result_type<float, int8_t> {
  using value_type = float;
};
template <> struct result_type<float, uint8_t> {
  using value_type = float;
};
template <> struct result_type<float, int16_t> {
  using value_type = float;
};
template <> struct result_type<float, uint16_t> {
  using value_type = float;
};
template <> struct result_type<float, int32_t> {
  using value_type = double;
};
template <> struct result_type<float, uint32_t> {
  using value_type = double;
};
template <> struct result_type<float, int64_t> {
  using value_type = double;
};
template <> struct result_type<float, uint64_t> {
  using value_type = double;
};
template <> struct result_type<float, float> {
  using value_type = float;
};
template <> struct result_type<float, double> {
  using value_type = double;
};
template <> struct result_type<float, cfloat> {
  using value_type = cfloat;
};
template <> struct result_type<float, cdouble> {
  using value_type = cdouble;
};
template <> struct result_type<double, int8_t> {
  using value_type = double;
};
template <> struct result_type<double, uint8_t> {
  using value_type = double;
};
template <> struct result_type<double, int16_t> {
  using value_type = double;
};
template <> struct result_type<double, uint16_t> {
  using value_type = double;
};
template <> struct result_type<double, int32_t> {
  using value_type = double;
};
template <> struct result_type<double, uint32_t> {
  using value_type = double;
};
template <> struct result_type<double, int64_t> {
  using value_type = double;
};
template <> struct result_type<double, uint64_t> {
  using value_type = double;
};
template <> struct result_type<double, float> {
  using value_type = double;
};
template <> struct result_type<double, double> {
  using value_type = double;
};
template <> struct result_type<double, cfloat> {
  using value_type = cdouble;
};
template <> struct result_type<double, cdouble> {
  using value_type = cdouble;
};
template <> struct result_type<cfloat, int8_t> {
  using value_type = cfloat;
};
template <> struct result_type<cfloat, uint8_t> {
  using value_type = cfloat;
};
template <> struct result_type<cfloat, int16_t> {
  using value_type = cfloat;
};
template <> struct result_type<cfloat, uint16_t> {
  using value_type = cfloat;
};
template <> struct result_type<cfloat, int32_t> {
  using value_type = cdouble;
};
template <> struct result_type<cfloat, uint32_t> {
  using value_type = cdouble;
};
template <> struct result_type<cfloat, int64_t> {
  using value_type = cdouble;
};
template <> struct result_type<cfloat, uint64_t> {
  using value_type = cdouble;
};
template <> struct result_type<cfloat, float> {
  using value_type = cfloat;
};
template <> struct result_type<cfloat, double> {
  using value_type = cdouble;
};
template <> struct result_type<cfloat, cfloat> {
  using value_type = cfloat;
};
template <> struct result_type<cfloat, cdouble> {
  using value_type = cdouble;
};
template <> struct result_type<cdouble, int8_t> {
  using value_type = cdouble;
};
template <> struct result_type<cdouble, uint8_t> {
  using value_type = cdouble;
};
template <> struct result_type<cdouble, int16_t> {
  using value_type = cdouble;
};
template <> struct result_type<cdouble, uint16_t> {
  using value_type = cdouble;
};
template <> struct result_type<cdouble, int32_t> {
  using value_type = cdouble;
};
template <> struct result_type<cdouble, uint32_t> {
  using value_type = cdouble;
};
template <> struct result_type<cdouble, int64_t> {
  using value_type = cdouble;
};
template <> struct result_type<cdouble, uint64_t> {
  using value_type = cdouble;
};
template <> struct result_type<cdouble, float> {
  using value_type = cdouble;
};
template <> struct result_type<cdouble, double> {
  using value_type = cdouble;
};
template <> struct result_type<cdouble, cfloat> {
  using value_type = cdouble;
};
template <> struct result_type<cdouble, cdouble> {
  using value_type = cdouble;
};

