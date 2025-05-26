#ifndef DETAIL_XIEITE_HEADER_PP_OR
#	define DETAIL_XIEITE_HEADER_PP_OR
#
#	include "../pp/bool.hpp"
#	include "../pp/if.hpp"
#
#	define XIEITE_OR(...) XIEITE_IF(__VA_ARGS__)(1)(XIEITE_BOOL)
#endif
