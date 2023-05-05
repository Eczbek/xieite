#pragma once

#if __has_include(<unistd.h>)
#	include <unistd.h>

#	if defined(_POSIX_VERSION)
#		if _POSIX_VERSION >= 198808
#			define XIEITE_STANDARD_UNIX_POSIX_1998
#		endif

#		if _POSIX_VERSION >= 199009
#			define XIEITE_STANDARD_UNIX_POSIX_1990
#		endif

#		if _POSIX_VERSION >= 199309
#			define XIEITE_STANDARD_UNIX_POSIX_1993
#		endif

#		if _POSIX_VERSION >= 199506
#			define XIEITE_STANDARD_UNIX_POSIX_1996
#		endif

#		if _POSIX_VERSION >= 200112
#			define XIEITE_STANDARD_UNIX_POSIX_2001
#		endif

#		if _POSIX_VERSION >= 200809
#			define XIEITE_STANDARD_UNIX_POSIX_2008
#		endif
#	endif

#	if defined(_POSIX2_C_VERSION) && (_POSIX2_C_VERSION >= 199209)
#		define XIEITE_STANDARD_UNIX_POSIX_1992
#	endif

#	if defined(_XOPEN_VERSION)
#		if _XOPEN_VERSION >= 3
#			define XIEITE_STANDARD_UNIX_XOPEN_1989
#		endif

#		if _XOPEN_VERSION >= 4
#			define XIEITE_STANDARD_UNIX_XOPEN_1992
#		endif

#		if (_XOPEN_VERSION >= 4) && defined(_XOPEN_UNIX)
#			define XIEITE_STANDARD_UNIX_XOPEN_1995
#		endif

#		if _XOPEN_VERSION >= 500
#			define XIEITE_STANDARD_UNIX_XOPEN_1998
#		endif

#		if _XOPEN_VERSION >= 600
#			define XIEITE_STANDARD_UNIX_XOPEN_2003
#		endif

#		if _XOPEN_VERSION >= 700
#			define XIEITE_STANDARD_UNIX_XOPEN_2008
#		endif
#	endif

#	if defined(__LSB_VERSION__)
#		define XIEITE_STANDARD_UNIX_LSB
#	endif
#endif
