#pragma once

#include <concepts>
#include <type_traits>

#define XIEITE_FWD(...) static_cast<decltype(__VA_ARGS__)&&>(__VA_ARGS__)
#define XIEITE_FWD_PRVALUE(...) XIEITE_DETAIL_FWD_PRVALUE(, __VA_ARGS__)
#define XIEITE_FWD_PRVALUE_LOCAL(...) XIEITE_DETAIL_FWD_PRVALUE(&, __VA_ARGS__)

#define XIEITE_DETAIL_FWD_PRVALUE(capture_, ...) \
	([capture_]<bool needs_cast = !::std::is_reference_v<decltype((__VA_ARGS__))> && ::std::same_as<decltype(__VA_ARGS__), decltype(__VA_ARGS__)>, typename Dest = decltype(__VA_ARGS__)> -> decltype(auto) { \
		if constexpr (needs_cast) { \
			return static_cast<Dest>(__VA_ARGS__); \
		} else { \
			return (__VA_ARGS__); \
		} \
	})()
