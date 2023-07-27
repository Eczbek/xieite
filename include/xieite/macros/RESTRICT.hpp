#ifndef XIEITE_HEADER_MACROS_RESTRICT
#	define XIEITE_HEADER_MACROS_RESTRICT

#	include "../macros/COMPILER_TYPE.hpp"

#	define XIEITE_RESTRICT

#	if XIEITE_COMPILER_TYPE_GCC
#		undef XIEITE_RESTRICT
#		define XIEITE_RESTRICT __restrict__
#	endif

#	if XIEITE_COMPILER_TYPE_LLVM || XIEITE_COMPILER_TYPE_MSVC
#		undef XIEITE_RESTRICT
#		define XIEITE_RESTRICT __restrict
#	endif

// Thanks to eightfold for original code

#endif
