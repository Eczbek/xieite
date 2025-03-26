#ifndef DETAIL_XIEITE_HEADER_PP_FWD
#	define DETAIL_XIEITE_HEADER_PP_FWD
#
#	include <concepts>
#	include <type_traits>
#
#	define XIEITE_FWD(...) static_cast<decltype(__VA_ARGS__)&&>(__VA_ARGS__)
#	define XIEITE_FWD_PRVALUE(...) DETAIL_XIEITE_FWD_PRVALUE(, __VA_ARGS__)
#	define XIEITE_FWD_PRVALUE_LOCAL(...) DETAIL_XIEITE_FWD_PRVALUE(&, __VA_ARGS__)
#
#	define DETAIL_XIEITE_FWD_PRVALUE(capture_, ...) \
	([capture_]<bool DETAIL_XIEITE_castable = !::std::is_reference_v<decltype((__VA_ARGS__))> && ::std::same_as<decltype(__VA_ARGS__), decltype(__VA_ARGS__)>, typename DETAIL_XIEITE_type = decltype(__VA_ARGS__)> -> decltype(auto) { \
		if constexpr (DETAIL_XIEITE_castable) { \
			return static_cast<DETAIL_XIEITE_type>(__VA_ARGS__); \
		} else { \
			return (__VA_ARGS__); \
		} \
	})()
#endif
