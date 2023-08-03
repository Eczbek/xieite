#ifndef XIEITE_HEADER_MACROS_VANISH
#	define XIEITE_HEADER_MACROS_VANISH

#	include "../macros/COMPILER_TYPE.hpp"

#	if XIEITE_COMPILER_TYPE_GCC
#		define XIEITE_VANISH sizeof(decltype(std))
#	else
#		define XIEITE_VANISH
#	endif

#endif
