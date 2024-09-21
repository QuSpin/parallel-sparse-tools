#pragma once

#include "result.h"

template<typename T, typename U>
decltype(auto) operator+(const T& t, const U& u) {
    using res_t = result_type_t<T, U>;
    return static_cast<res_t>(t) + static_cast<res_t>(u);
}

template<typename T, typename U>
decltype(auto) operator-(const T& t, const U& u) {
    using res_t = result_type_t<T, U>;
    return static_cast<res_t>(t) - static_cast<res_t>(u);
}

template<typename T, typename U>
decltype(auto) operator*(const T& t, const U& u) {
    using res_t = result_type_t<T, U>;
    return static_cast<res_t>(t) * static_cast<res_t>(u);
}

template<typename T, typename U>
decltype(auto) operator/(const T& t, const U& u) {
    using res_t = result_type_t<T, U>;
    return static_cast<res_t>(t) / static_cast<res_t>(u);
}


// operator+ition
