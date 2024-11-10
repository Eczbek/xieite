#pragma once

#if __has_include(<unistd.h>)
#	include <unistd.h>
#endif

#define XIEITE_UNIX_TYPE_POSIX 0
#define XIEITE_UNIX_MAJOR_POSIX 0
#define XIEITE_UNIX_MINOR_POSIX 0
#define XIEITE_UNIX_PATCH_POSIX 0
#define XIEITE_UNIX_TYPE_X_OPEN 0
#define XIEITE_UNIX_MAJOR_X_OPEN 0
#define XIEITE_UNIX_MINOR_X_OPEN 0
#define XIEITE_UNIX_PATCH_X_OPEN 0
#define XIEITE_UNIX_TYPE_LSB 0
#define XIEITE_UNIX_MAJOR_LSB 0
#define XIEITE_UNIX_MINOR_LSB 0
#define XIEITE_UNIX_PATCH_LSB 0

#define XIEITE_UNIX_EQ(type, major, ...) XIEITE_DETAIL_UNIX_SEL(__VA_ARGS__, XIEITE_DETAIL_UNIX_EQ(type, major, __VA_ARGS__), XIEITE_DETAIL_UNIX_EQ(type, major, __VA_ARGS__, 0), XIEITE_DETAIL_UNIX_EQ(type, major, 0, 0))
#define XIEITE_UNIX_LEAST(type, major, ...) XIEITE_DETAIL_UNIX_SEL(__VA_ARGS__, XIEITE_DETAIL_UNIX_LEAST(type, major, __VA_ARGS__), XIEITE_DETAIL_UNIX_LEAST(type, major, __VA_ARGS__, 0), XIEITE_DETAIL_UNIX_LEAST(type, major, 0, 0))
#define XIEITE_UNIX_MOST(type, major, ...) XIEITE_DETAIL_UNIX_SEL(__VA_ARGS__, XIEITE_DETAIL_UNIX_MOST(type, major, __VA_ARGS__), XIEITE_DETAIL_UNIX_MOST(type, major, __VA_ARGS__, 0), XIEITE_DETAIL_UNIX_MOST(type, major, 0, 0))
#define XIEITE_DETAIL_UNIX_SEL(_0, _1, _2, x, ...) x
#define XIEITE_DETAIL_UNIX_EQ(type, major, minor, patch) (XIEITE_UNIX_TYPE_##type && (XIEITE_UNIX_MAJOR_##type == (major)) && (XIEITE_UNIX_MINOR_##type == (minor)) && (XIEITE_UNIX_PATCH_##type == (patch)))
#define XIEITE_DETAIL_UNIX_LEAST(type, major, minor, patch) (XIEITE_UNIX_TYPE_##type && ((XIEITE_UNIX_MAJOR_##type > (major)) || (XIEITE_UNIX_MAJOR_##type == (major)) && ((XIEITE_UNIX_MINOR_##type > (minor)) || (XIEITE_UNIX_MINOR_##type == (minor)) && (XIEITE_UNIX_PATCH_##type >= (patch)))))
#define XIEITE_DETAIL_UNIX_MOST(type, major, minor, patch) (XIEITE_UNIX_TYPE_##type && ((XIEITE_UNIX_MAJOR_##type < (major)) || (XIEITE_UNIX_MAJOR_##type == (major)) && ((XIEITE_UNIX_MINOR_##type < (minor)) || (XIEITE_UNIX_MINOR_##type == (minor)) && (XIEITE_UNIX_PATCH_##type <= (patch)))))

#ifdef _POSIX_VERSION
#	undef XIEITE_UNIX_TYPE_POSIX
#	define XIEITE_UNIX_TYPE_POSIX 1

#	undef XIEITE_UNIX_MAJOR_POSIX
#	if defined(_POSIX2_C_VERSION) && (_POSIX2_C_VERSION > _POSIX_VERSION)
#		define XIEITE_UNIX_MAJOR_POSIX (_POSIX2_C_VERSION / 100)
#	else
#		define XIEITE_UNIX_MAJOR_POSIX (_POSIX_VERSION / 100)
#	endif
#endif

#ifdef _XOPEN_VERSION
#	undef XIEITE_UNIX_TYPE_X_OPEN
#	define XIEITE_UNIX_TYPE_X_OPEN 1

#	undef XIEITE_UNIX_MAJOR_X_OPEN
#	if _XOPEN_VERSION >= 3
#		define XIEITE_UNIX_MAJOR_X_OPEN 1989
#	elif _XOPEN_VERSION >= 4
#		define XIETIE_UNIX_MAJOR_X_OPEN 1992
#	elif (_XOPEN_VERSION >= 4) && defined(_XOPEN_UNIX)
#		define XIEITE_UNIX_MAJOR_X_OPEN 1995
#	elif _XOPEN_VERSION >= 500
#		define XIEITE_UNIX_MAJOR_X_OPEN 1998
#	elif _XOPEN_VERSION >= 600
#		define XIEITE_UNIX_MAJOR_X_OPEN 2003
#	elif _XOPEN_VERSION >= 700
#		define XIEITE_UNIX_MAJOR_X_OPEN 2008
#	endif
#endif

#ifdef __LSB_VERSION__
#	undef XIEITE_UNIX_TYPE_LSB
#	define XIEITE_UNIX_TYPE_LSB 1

#	undef XIEITE_UNIX_MAJOR_LSB
#	define XIEITE_UNIX_MAJOR_LSB (__LSB_VERSION__ / 10)

#	undef XIEITE_UNIX_MINOR_LSB
#	define XIEITE_UNIX_MINOR_LSB (__LSB_VERSION__ % 10)
#endif

// https://github.com/cpredef/predef/blob/master/Standards.md#unix-standards
