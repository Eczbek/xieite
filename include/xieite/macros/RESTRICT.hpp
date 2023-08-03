#ifndef XIEITE_HEADER_MACROS_RESTRICT
#	define XIEITE_HEADER_MACROS_RESTRICT

#	include "../macros/COMPILER_TYPE.hpp"

#	if XIEITE_COMPILER_TYPE_GCC
#		define XIEITE_RESTRICT __restrict__
#	elif XIEITE_COMPILER_TYPE_LLVM || XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_RESTRICT __restrict
#	else
#		define XIEITE_RESTRICT
#	endif

// Thanks to eightfold for original code

#endif
