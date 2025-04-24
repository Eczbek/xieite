#ifndef DETAIL_XIEITE_HEADER_PP_OUT
#	define DETAIL_XIEITE_HEADER_PP_OUT
#
#	include "../pp/arrow.hpp"
#	include "../pp/diag.hpp"

XIEITE_DIAG_OFF_CLANG("-Wdollar-in-identifier-extension")

#	define XIEITE_OUT(...) \
		[](auto&& $ = {}) mutable \
			XIEITE_ARROW(void(__VA_ARGS__), $)
#	define XIEITE_OUT_LOCAL(...) \
		[&](auto&& $ = {}) mutable \
			XIEITE_ARROW(void(__VA_ARGS__), $)
#endif
