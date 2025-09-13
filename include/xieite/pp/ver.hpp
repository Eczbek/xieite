#ifndef DETAIL_XIEITE_HEADER_PP_VER
#	define DETAIL_XIEITE_HEADER_PP_VER
#
#	define XIEITE_VER_MAJOR 0
#	define XIEITE_VER_MINOR 122
#	define XIEITE_VER_PATCH 0
#	define XIEITE_VER(_cmp, _major, ...) DETAIL_XIEITE_VER(_cmp, _major, __VA_ARGS__ __VA_OPT__(,) 0, 0)
#
#	define DETAIL_XIEITE_VER(_cmp, _major, _minor, _patch, ...) (((((0 _cmp 0) && !(0 _cmp 1) && !(1 _cmp 0)) || (!(0 _cmp 0) && (0 _cmp 1) && (1 _cmp 0))) && (((XIEITE_VER_MAJOR) _cmp (_major)) && ((XIEITE_VER_MINOR) _cmp (_minor)) && ((XIEITE_VER_PATCH) _cmp (_patch)))) || ((XIEITE_VER_MAJOR) _cmp (_major)) || (((XIEITE_VER_MAJOR) == (_major)) && ((XIEITE_VER_MINOR) _cmp (_minor))) || (((XIEITE_VER_MINOR) == (_minor)) && ((XIEITE_VER_PATCH) _cmp (_patch))))
#endif
