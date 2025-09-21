#ifndef DETAIL_XIEITE_HEADER_PP_VER
#	define DETAIL_XIEITE_HEADER_PP_VER
#
#	define XIEITE_VER_MAJOR 0
#	define XIEITE_VER_MINOR 126
#	define XIEITE_VER_PATCH 0
#	define XIEITE_VER(_op, _major, ...) DETAIL_XIEITE_VER(_op, _major, __VA_ARGS__ __VA_OPT__(,) 0, 0)
#
#	define DETAIL_XIEITE_VER(_op, _major, _minor, _patch, ...) (((((0 _op 0) && !(0 _op 1) && !(1 _op 0)) || (!(0 _op 0) && (0 _op 1) && (1 _op 0))) && (((XIEITE_VER_MAJOR) _op (_major)) && ((XIEITE_VER_MINOR) _op (_minor)) && ((XIEITE_VER_PATCH) _op (_patch)))) || ((XIEITE_VER_MAJOR) _op (_major)) || (((XIEITE_VER_MAJOR) == (_major)) && ((XIEITE_VER_MINOR) _op (_minor))) || (((XIEITE_VER_MINOR) == (_minor)) && ((XIEITE_VER_PATCH) _op (_patch))))
#endif
