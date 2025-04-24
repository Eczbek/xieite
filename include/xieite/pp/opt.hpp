#ifndef DETAIL_XIEITE_HEADER_PP_OPT
#	define DETAIL_XIEITE_HEADER_PP_OPT
#
#	include "../pp/if.hpp"
#	include "../pp/none.hpp"
#	include "../pp/unwrap.hpp"
#
#	define XIEITE_OPT(...) XIEITE_IF(XIEITE_NONE(XIEITE_UNWRAP(__VA_ARGS__)))()
#endif
