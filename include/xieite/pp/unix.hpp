#ifndef DETAIL_XIEITE_HEADER_PP_UNIX
#	define DETAIL_XIEITE_HEADER_PP_UNIX
#
#	define XIEITE_UNIX_TYPE_POSIX 0
#	define XIEITE_UNIX_MAJOR_POSIX 0
#	define XIEITE_UNIX_MINOR_POSIX 0
#	define XIEITE_UNIX_PATCH_POSIX 0
#	define XIEITE_UNIX_TYPE_X_OPEN 0
#	define XIEITE_UNIX_MAJOR_X_OPEN 0
#	define XIEITE_UNIX_MINOR_X_OPEN 0
#	define XIEITE_UNIX_PATCH_X_OPEN 0
#	define XIEITE_UNIX_TYPE_LSB 0
#	define XIEITE_UNIX_MAJOR_LSB 0
#	define XIEITE_UNIX_MINOR_LSB 0
#	define XIEITE_UNIX_PATCH_LSB 0
#	define XIEITE_UNIX_VER(_type, _cmp, _major, ...) DETAIL_XIEITE_UNIX_VER(_cmp, XIEITE_UNIX_MAJOR_##_type, XIEITE_UNIX_MINOR_##_type, XIEITE_UNIX_PATCH_##_type, _major, __VA_ARGS__ __VA_OPT__(,) 0, 0)
#
#	define DETAIL_XIEITE_UNIX_VER(_cmp, _major0, _minor0, _patch0, _major1, _minor1, _patch1, ...) (((((0 _cmp 0) && !(0 _cmp 1) && !(1 _cmp 0)) || (!(0 _cmp 0) && (0 _cmp 1) && (1 _cmp 0))) && (((_major0) _cmp (_major1)) && ((_minor0) _cmp (_minor1)) && ((_patch0) _cmp (_patch1)))) || ((_major0) _cmp (_major1)) || (((_major0) == (_major1)) && ((_minor0) _cmp (_minor1))) || (((_minor0) == (_minor1)) && ((_patch0) _cmp (_patch1))))
#
#	if __has_include(<unistd.h>)
#		include <unistd.h>
#	endif
#
#	ifdef _POSIX_VERSION
#		undef XIEITE_UNIX_TYPE_POSIX
#		define XIEITE_UNIX_TYPE_POSIX 1
#
#		undef XIEITE_UNIX_MAJOR_POSIX
#		if _POSIX2_C_VERSION > _POSIX_VERSION
#			define XIEITE_UNIX_MAJOR_POSIX (_POSIX2_C_VERSION / 100)
#		else
#			define XIEITE_UNIX_MAJOR_POSIX (_POSIX_VERSION / 100)
#		endif
#	endif
#
#	ifdef _XOPEN_VERSION
#		undef XIEITE_UNIX_TYPE_X_OPEN
#		define XIEITE_UNIX_TYPE_X_OPEN 1
#
#		undef XIEITE_UNIX_MAJOR_X_OPEN
#		if _XOPEN_VERSION >= 3
#			define XIEITE_UNIX_MAJOR_X_OPEN 1989
#		elif _XOPEN_VERSION >= 4
#			define XIEITE_UNIX_MAJOR_X_OPEN 1992
#		elif (_XOPEN_VERSION >= 4) && defined(_XOPEN_UNIX)
#			define XIEITE_UNIX_MAJOR_X_OPEN 1995
#		elif _XOPEN_VERSION >= 500
#			define XIEITE_UNIX_MAJOR_X_OPEN 1998
#		elif _XOPEN_VERSION >= 600
#			define XIEITE_UNIX_MAJOR_X_OPEN 2003
#		elif _XOPEN_VERSION >= 700
#			define XIEITE_UNIX_MAJOR_X_OPEN 2008
#		endif
#	endif
#
#	ifdef __LSB_VERSION__
#		undef XIEITE_UNIX_TYPE_LSB
#		define XIEITE_UNIX_TYPE_LSB 1
#
#		undef XIEITE_UNIX_MAJOR_LSB
#		define XIEITE_UNIX_MAJOR_LSB (__LSB_VERSION__ / 10)
#
#		undef XIEITE_UNIX_MINOR_LSB
#		define XIEITE_UNIX_MINOR_LSB (__LSB_VERSION__ % 10)
#	endif
#endif

// https://github.com/cpredef/predef/blob/master/Standards.md#unix-standards
