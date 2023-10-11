#ifndef XIEITE_HEADER_MACROS_PACKED
#	define XIEITE_HEADER_MACROS_PACKED

#	include "../macros/compiler.hpp"

#	if XIEITE_COMPILER_GCC
#		define XIEITE_PACKED [[gnu::packed]]
#	else
#		define XIEITE_PACKED
#	endif

#endif
