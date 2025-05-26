#ifndef DETAIL_XIEITE_HEADER_PP_AND
#	define DETAIL_XIEITE_HEADER_PP_AND
#
#	include "../pp/bool.hpp"
#	include "../pp/if.hpp"
#
#	define XIEITE_AND(...) XIEITE_IF(__VA_ARGS__)(XIEITE_BOOL)(0)
#endif
