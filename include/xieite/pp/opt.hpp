#ifndef DETAIL_XIEITE_HEADER_PP_OPT
#	define DETAIL_XIEITE_HEADER_PP_OPT
#
#	include "../pp/any.hpp"
#	include "../pp/if.hpp"
#	include "../pp/unwrap.hpp"
#
#	define XIEITE_OPT(...) XIEITE_IF(XIEITE_ANY(XIEITE_UNWRAP(__VA_ARGS__)))
#endif
