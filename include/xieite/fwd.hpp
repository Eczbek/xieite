#pragma once

#include <concepts>
#include <type_traits>

#define XIEITE_FWD(...) static_cast<decltype(__VA_ARGS__)&&>(__VA_ARGS__)
#define XIEITE_FWD_PRVALUE(...) \
	([&]<int = 0> -> decltype(auto) { \
		if constexpr (!::std::same_as<decltype(__VA_ARGS__), decltype((__VA_ARGS__))> && ::std::same_as<decltype(__VA_ARGS__), decltype(__VA_ARGS__)>) { \
			return static_cast<::std::add_rvalue_reference_t<decltype(__VA_ARGS__)>>(__VA_ARGS__); \
		} else { \
			return (__VA_ARGS__); \
		} \
	})()

// The `static_cast` is translated unless the condition of the `if constexpr` is both dependent and false
