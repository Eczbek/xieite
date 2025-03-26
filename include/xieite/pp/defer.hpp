#ifndef DETAIL_XIEITE_HEADER_PP_DEFER
#	define DETAIL_XIEITE_HEADER_PP_DEFER
#
#	include "../pp/eat.hpp"
#
#	define XIEITE_DEFER(...) __VA_ARGS__ XIEITE_EAT()
#endif
