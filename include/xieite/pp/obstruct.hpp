#ifndef DETAIL_XIEITE_HEADER_PP_OBSTRUCT
#	define DETAIL_XIEITE_HEADER_PP_OBSTRUCT
#
#	include "../pp/defer.hpp"
#	include "../pp/eat.hpp"
#
#	define XIEITE_OBSTRUCT(...) __VA_ARGS__ XIEITE_DEFER(XIEITE_EAT)()
#endif
