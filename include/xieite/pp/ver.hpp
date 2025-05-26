#ifndef DETAIL_XIEITE_HEADER_PP_VER
#	define DETAIL_XIEITE_HEADER_PP_VER
#
#	define XIEITE_VER_MAJOR 0
#	define XIEITE_VER_MINOR 88
#	define XIEITE_VER_PATCH 0
#	define XIEITE_VER(type, cmp, major, ...) DETAIL_XIEITE_VER(cmp, major, __VA_ARGS__ __VA_OPT__(,) 0, 0)
#
#	define DETAIL_XIEITE_VER(cmp, major, minor, patch, ...) (((((0 cmp 0) && !(0 cmp 1) && !(1 cmp 0)) || (!(0 cmp 0) && (0 cmp 1) && (1 cmp 0))) && (((XIEITE_VER_MAJOR) cmp (major)) && ((XIEITE_VER_MINOR) cmp (minor)) && ((XIEITE_VER_PATCH) cmp (patch)))) || ((XIEITE_VER_MAJOR) cmp (major)) || (((XIEITE_VER_MAJOR) == (major)) && ((XIEITE_VER_MINOR) cmp (minor))) || (((XIEITE_VER_MINOR) == (minor)) && ((XIEITE_VER_PATCH) cmp (patch))))
#endif
