#ifndef __oputils_result_h__
#define __oputils_result_h__

#include <type_traits>

template <typename... T> struct result_type {};

template <typename... T> using result_type_t = typename result_type<T...>::type;

template <typename T, typename... Ts> struct result_type<T, Ts...> {
  using type =
      decltype(std::declval<T>() + std::declval<result_type_t<Ts...>>());
};

template <typename T> struct result_type<T> {
  using type = T;
};

#endif // __oputils_result_h__
