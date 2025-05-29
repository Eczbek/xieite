#ifndef DETAIL_XIEITE_HEADER_PP_NOT
#	define DETAIL_XIEITE_HEADER_PP_NOT
#
#	include "../pp/check.hpp"
#	include "../pp/cat.hpp"
#	include "../pp/probe.hpp"
#
#	define XIEITE_NOT(_x) XIEITE_CHECK(XIEITE_PCAT(DETAIL_XIEITE_NOT_, _x))
#
#	define DETAIL_XIEITE_NOT_0 XIEITE_PROBE(~)
#endif
