#ifndef DETAIL_XTE_HEADER_PREPROC_VERSION
#	define DETAIL_XTE_HEADER_PREPROC_VERSION
#
#	define XTE_VERSION_MAJOR 0
#	define XTE_VERSION_MINOR 127
#	define XTE_VERSION_PATCH 0
#	define XTE_VERSION(_op, _major, ...) DETAIL_XIEITE_VERSION(_op, _major, __VA_ARGS__ __VA_OPT__(,) 0, 0)
#
#	define DETAIL_XIEITE_VERSION(_op, _major, _minor, _patch, ...) (((((0 _op 0) && !(0 _op 1) && !(1 _op 0)) || (!(0 _op 0) && (0 _op 1) && (1 _op 0))) && (((XTE_VERSION_MAJOR) _op (_major)) && ((XTE_VERSION_MINOR) _op (_minor)) && ((XTE_VERSION_PATCH) _op (_patch)))) || ((XTE_VERSION_MAJOR) _op (_major)) || (((XTE_VERSION_MAJOR) == (_major)) && ((XTE_VERSION_MINOR) _op (_minor))) || (((XTE_VERSION_MINOR) == (_minor)) && ((XTE_VERSION_PATCH) _op (_patch))))
#endif
