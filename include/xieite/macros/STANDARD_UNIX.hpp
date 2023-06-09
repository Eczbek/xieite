#ifndef XIEITE_HEADER_MACROS_STANDARD_UNIX
#	define XIEITE_HEADER_MACROS_STANDARD_UNIX

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_UNIX
#		include <unistd.h>

#		ifdef _POSIX_VERSION
#			define XIEITE_STANDARD_UNIX_POSIX_1998 false
#			if (_POSIX_VERSION >= 198808)
#				define XIEITE_STANDARD_UNIX_POSIX_1998 true
#			endif

#			define XIEITE_STANDARD_UNIX_POSIX_1990 false
#			if (_POSIX_VERSION >= 199009)
#				define XIEITE_STANDARD_UNIX_POSIX_1990 true
#			endif

#			define XIEITE_STANDARD_UNIX_POSIX_1993 false
#			if (_POSIX_VERSION >= 199309)
#				define XIEITE_STANDARD_UNIX_POSIX_1993 true
#			endif

#			define XIEITE_STANDARD_UNIX_POSIX_1996 false
#			if (_POSIX_VERSION >= 199506)
#				define XIEITE_STANDARD_UNIX_POSIX_1996 true
#			endif

#			define XIEITE_STANDARD_UNIX_POSIX_2001 false
#			if (_POSIX_VERSION >= 200112)
#				define XIEITE_STANDARD_UNIX_POSIX_2001 true
#			endif

#			define XIEITE_STANDARD_UNIX_POSIX_2008 false
#			if (_POSIX_VERSION >= 200809)
#				define XIEITE_STANDARD_UNIX_POSIX_2008 true
#			endif
#		endif

#		define XIEITE_STANDARD_UNIX_POSIX_1992 false
#		if defined(_POSIX2_C_VERSION) && (_POSIX2_C_VERSION >= 199209)
#			define XIEITE_STANDARD_UNIX_POSIX_1992 true
#		endif

#		ifdef _XOPEN_VERSION
#			define XIEITE_STANDARD_UNIX_XOPEN_1989 false
#			if (_XOPEN_VERSION >= 3)
#				define XIEITE_STANDARD_UNIX_XOPEN_1989 true
#			endif

#			define XIEITE_STANDARD_UNIX_XOPEN_1992 false
#			if (_XOPEN_VERSION >= 4)
#				define XIEITE_STANDARD_UNIX_XOPEN_1992 true
#			endif

#			define XIEITE_STANDARD_UNIX_XOPEN_1995 false
#			if (_XOPEN_VERSION >= 4) && defined(_XOPEN_UNIX)
#				define XIEITE_STANDARD_UNIX_XOPEN_1995 true
#			endif

#			define XIEITE_STANDARD_UNIX_XOPEN_1998 false
#			if (_XOPEN_VERSION >= 500)
#				define XIEITE_STANDARD_UNIX_XOPEN_1998 true
#			endif

#			define XIEITE_STANDARD_UNIX_XOPEN_2003 false
#			if (_XOPEN_VERSION >= 600)
#				define XIEITE_STANDARD_UNIX_XOPEN_2003 true
#			endif

#			define XIEITE_STANDARD_UNIX_XOPEN_2008 false
#			if (_XOPEN_VERSION >= 700)
#				define XIEITE_STANDARD_UNIX_XOPEN_2008 true
#			endif
#		endif

#		define XIEITE_STANDARD_UNIX_LSB false
#		ifdef __LSB_VERSION__
#			define XIEITE_STANDARD_UNIX_LSB true
#		endif
#	else
#		error "System not supported"
#	endif

#endif
