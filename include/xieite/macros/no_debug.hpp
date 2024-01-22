#ifndef XIEITE_HEADER_MACROS_NO_DEBUG
#	define XIEITE_HEADER_MACROS_NO_DEBUG

#	include "../macros/compiler_type.hpp"
#	include "../macros/has_attribute.hpp"

#	if (XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG) && XIEITE_HAS_ATTRIBUTE(__nodebug__)
#		define XIEITE_NO_DEBUG __attribute__((__nodebug__))
#	else
#		define XIEITE_NO_DEBUG
#	endif

#endif

// Thanks to Ian Pike for original code
// https://github.com/Rinzii
