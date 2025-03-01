#pragma once

#include <concepts>
#include <type_traits>

#define X4FWD(...) static_cast<decltype(__VA_ARGS__)&&>(__VA_ARGS__)
#define X4FWDPRVALUE(...) DETAIL_X4FWDPRVALUE(, __VA_ARGS__)
#define X4FWDPRVALUELOC(...) DETAIL_X4FWDPRVALUE(&, __VA_ARGS__)

#define DETAIL_X4FWDPRVALUE(capture_, ...) \
	([capture_]<bool needs_cast = !::std::is_reference_v<decltype((__VA_ARGS__))> && ::std::same_as<decltype(__VA_ARGS__), decltype(__VA_ARGS__)>, typename Dest = decltype(__VA_ARGS__)> -> decltype(auto) { \
		if constexpr (needs_cast) { \
			return static_cast<Dest>(__VA_ARGS__); \
		} else { \
			return (__VA_ARGS__); \
		} \
	})()
