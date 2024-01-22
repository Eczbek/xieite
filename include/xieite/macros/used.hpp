#ifndef XIEITE_HEADER_MACROS_USED
#	define XIEITE_HEADER_MACROR_USED

#	include "../macros/compiler_type.hpp"

#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_USED __attribute__((__used__))
#	else
#		define XIEITE_USED
#	endif

#endif
