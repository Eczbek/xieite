#pragma once

#if __has_include(<unistd.h>)
#	include <unistd.h>
#endif

#define X4UNIX_POSIX 0
#define X4UNIXMAJOR_POSIX 0
#define X4UNIXMINOR_POSIX 0
#define X4UNIXPATCH_POSIX 0
#define X4UNIX_X_OPEN 0
#define X4UNIXMAJOR_X_OPEN 0
#define X4UNIXMINOR_X_OPEN 0
#define X4UNIXPATCH_X_OPEN 0
#define X4UNIX_LSB 0
#define X4UNIXMAJOR_LSB 0
#define X4UNIXMINOR_LSB 0
#define X4UNIXPATCH_LSB 0

#define X4UNIXEQ(type, major, ...) DETAIL_X4UNIX(__VA_ARGS__, DETAIL_X4UNIXEQ(type, major, __VA_ARGS__), DETAIL_X4UNIXEQ(type, major, __VA_ARGS__, 0), DETAIL_X4UNIXEQ(type, major, 0, 0))
#define X4UNIXLEAST(type, major, ...) DETAIL_X4UNIX(__VA_ARGS__, DETAIL_X4UNIXLEAST(type, major, __VA_ARGS__), DETAIL_X4UNIXLEAST(type, major, __VA_ARGS__, 0), DETAIL_X4UNIXLEAST(type, major, 0, 0))
#define X4UNIXMOST(type, major, ...) DETAIL_X4UNIX(__VA_ARGS__, DETAIL_X4UNIXMOST(type, major, __VA_ARGS__), DETAIL_X4UNIXMOST(type, major, __VA_ARGS__, 0), DETAIL_X4UNIXMOST(type, major, 0, 0))
#define DETAIL_X4UNIX(_0, _1, _2, x, ...) x
#define DETAIL_X4UNIXEQ(type, major, minor, patch) (X4UNIX_##type && (X4UNIXMAJOR_##type == (major)) && (X4UNIXMINOR_##type == (minor)) && (X4UNIXPATCH_##type == (patch)))
#define DETAIL_X4UNIXLEAST(type, major, minor, patch) (X4UNIX_##type && ((X4UNIXMAJOR_##type > (major)) || (X4UNIXMAJOR_##type == (major)) && ((X4UNIXMINOR_##type > (minor)) || (X4UNIXMINOR_##type == (minor)) && (X4UNIXPATCH_##type >= (patch)))))
#define DETAIL_X4UNIXMOST(type, major, minor, patch) (X4UNIX_##type && ((X4UNIXMAJOR_##type < (major)) || (X4UNIXMAJOR_##type == (major)) && ((X4UNIXMINOR_##type < (minor)) || (X4UNIXMINOR_##type == (minor)) && (X4UNIXPATCH_##type <= (patch)))))

#ifdef _POSIX_VERSION
#	undef X4UNIX_POSIX
#	define X4UNIX_POSIX 1

#	undef X4UNIXMAJOR_POSIX
#	if defined(_POSIX2_C_VERSION) && (_POSIX2_C_VERSION > _POSIX_VERSION)
#		define X4UNIXMAJOR_POSIX (_POSIX2_C_VERSION / 100)
#	else
#		define X4UNIXMAJOR_POSIX (_POSIX_VERSION / 100)
#	endif
#endif

#ifdef _XOPEN_VERSION
#	undef X4UNIX_X_OPEN
#	define X4UNIX_X_OPEN 1

#	undef X4UNIXMAJOR_X_OPEN
#	if _XOPEN_VERSION >= 3
#		define X4UNIXMAJOR_X_OPEN 1989
#	elif _XOPEN_VERSION >= 4
#		define X4UNIXMAJOR_X_OPEN 1992
#	elif (_XOPEN_VERSION >= 4) && defined(_XOPEN_UNIX)
#		define X4UNIXMAJOR_X_OPEN 1995
#	elif _XOPEN_VERSION >= 500
#		define X4UNIXMAJOR_X_OPEN 1998
#	elif _XOPEN_VERSION >= 600
#		define X4UNIXMAJOR_X_OPEN 2003
#	elif _XOPEN_VERSION >= 700
#		define X4UNIXMAJOR_X_OPEN 2008
#	endif
#endif

#ifdef __LSB_VERSION__
#	undef X4UNIX_LSB
#	define X4UNIX_LSB 1

#	undef X4UNIXMAJOR_LSB
#	define X4UNIXMAJOR_LSB (__LSB_VERSION__ / 10)

#	undef X4UNIXMINOR_LSB
#	define X4UNIXMINOR_LSB (__LSB_VERSION__ % 10)
#endif
