#ifndef XIEITE_HEADER_MACROS_VANISH
#	define XIEITE_HEADER_MACROS_VANISH

#	include <xieite/macros/COMPILER_TYPE.hpp>

#	define XIEITE_VANISH

#	if XIEITE_COMPILER_TYPE_GCC
#		undef XIEITE_VANISH
#		define XIEITE_VANISH sizeof(decltype(std))
#	endif

#endif
