#ifndef DETAIL_XIEITE_HEADER_PP_IF
#	define DETAIL_XIEITE_HEADER_PP_IF
#
#	include "../pp/bool.hpp"
#	include "../pp/cat.hpp"
#	include "../pp/eat.hpp"
#	include "../pp/scan.hpp"
#
#	define XIEITE_IF(_x) XIEITE_IIF(XIEITE_BOOL(_x))
#	define XIEITE_IIF(_b) XIEITE_PCAT(DETAIL_XIEITE_IF_, _b)
#
#	define DETAIL_XIEITE_IF_0(...) XIEITE_SCAN
#	define DETAIL_XIEITE_IF_1(...) __VA_ARGS__ XIEITE_EAT
#endif
