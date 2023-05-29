#ifndef XIEITE_HEADER_MACROS_VANISH
#	define XIEITE_HEADER_MACROS_VANISH

#	include <xieite/macros/COMPILER_TYPE.hpp>

#	ifdef XIEITE_COMPILER_TYPE_GCC
#		define XIEITE_VANISH \
			sizeof(decltype(std))
#	else
#		error "Compiler not supported"
#	endif

#endif
