#ifndef DETAIL_XIEITE_HEADER_PP_VER
#	define DETAIL_XIEITE_HEADER_PP_VER
#
#	include "../pp/ver_cmp.hpp"
#
#	define XIEITE_VER_MAJOR 0
#	define XIEITE_VER_MINOR 82
#	define XIEITE_VER_PATCH 1
#
#	define XIEITE_VER(cmp, major, ...) XIEITE_VER_CMP(cmp, XIEITE_VER_MAJOR, XIEITE_VER_MINOR, XIEITE_VER_PATCH, major, __VA_ARGS__)
#endif
