#ifndef DETAIL_XTE_HEADER_PREPROC_VERSION
#	define DETAIL_XTE_HEADER_PREPROC_VERSION
#
#	define XTE_VERSION_MAJOR 0
#	define XTE_VERSION_MINOR 128
#	define XTE_VERSION_PATCH 1
#
#	define XTE_VERSION(_operator, _major, ...) \
		DETAIL_XTE_VERSION( \
			_operator, \
			_major, __VA_ARGS__ __VA_OPT__(,) 0, 0\
		)
#
#	define DETAIL_XTE_VERSION(_operator, _major, _minor, _patch, ...) \
		(((((0 _operator 0) && !(0 _operator 1) && !(1 _operator 0)) \
			|| (!(0 _operator 0) && (0 _operator 1) && (1 _operator 0))) \
		&& (((XTE_VERSION_MAJOR) _operator (_major)) \
			&& ((XTE_VERSION_MINOR) _operator (_minor)) \
			&& ((XTE_VERSION_PATCH) _operator (_patch)))) \
		|| ((XTE_VERSION_MAJOR) _operator (_major)) \
			|| (((XTE_VERSION_MAJOR) == (_major)) && ((XTE_VERSION_MINOR) _operator (_minor))) \
			|| (((XTE_VERSION_MINOR) == (_minor)) && ((XTE_VERSION_PATCH) _operator (_patch))))
#endif
