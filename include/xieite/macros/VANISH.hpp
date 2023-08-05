#ifndef XIEITE_HEADER__MACROS__VANISH
#	define XIEITE_HEADER__MACROS__VANISH

#	include "../macros/COMPILER_TYPE.hpp"

#	if XIEITE__COMPILER_TYPE__GCC
#		define XIEITE__VANISH sizeof(decltype(std))
#	else
#		define XIEITE__VANISH
#	endif

#endif
