#ifndef DETAIL_XIEITE_HEADER_PP_VER_CMP
#	define DETAIL_XIEITE_HEADER_PP_VER_CMP
#
#	define XIEITE_VER_CMP(cmp, major0, minor0, patch0, major1, ...) DETAIL_XIEITE_VER_CMP(cmp, major0, minor0, patch0, major1, __VA_ARGS__ __VA_OPT__(,) 0, 0)
#
#	define DETAIL_XIEITE_VER_CMP(cmp, major0, minor0, patch0, major1, minor1, patch1, ...) (((((0 cmp 0) && !(0 cmp 1) && !(1 cmp 0)) || (!(0 cmp 0) && (0 cmp 1) && (1 cmp 0))) && (((major0) cmp (major1)) && ((minor0) cmp (minor1)) && ((patch0) cmp (patch1)))) || ((major0) cmp (major1)) || (((major0) == (major1)) && ((minor0) cmp (minor1))) || (((minor0) == (minor1)) && ((patch0) cmp (patch1))))
#endif
