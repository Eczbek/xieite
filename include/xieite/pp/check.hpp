#ifndef DETAIL_XIEITE_HEADER_PP_CHECK
#	define DETAIL_XIEITE_HEADER_PP_CHECK
#
#	include "../pp/at.hpp"
#
#	define XIEITE_CHECK(...) XIEITE_AT_1(__VA_ARGS__, 0,)
#endif
