#ifndef XIEITE_HEADER__MACROS__PACKED
#	define XIEITE_HEADER__MACROS__PACKED

#	include "../macros/compiler_type.hpp"

#	if XIEITE__COMPILER_TYPE__GCC
#		define XIEITE__PACKED [[gnu::packed]]
#	else
#		define XIEITE__PACKED
#	endif

#endif
