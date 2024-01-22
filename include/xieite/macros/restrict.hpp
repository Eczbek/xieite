#ifndef XIEITE_HEADER_MACROS_RESTRICT
#	define XIEITE_HEADER_MACROS_RESTRICT

#	include "../macros/compiler_type.hpp"
#	include "../macros/language_standard.hpp"

#	if XIEITE_LANGUAGE_STANDARD_C_1999
#		define XIEITE_RESTRICT restrict
#	elif XIEITE_COMPILER_TYPE_GCC
#		define XIEITE_RESTRICT __restrict__
#	elif XIEITE_COMPILER_TYPE_LLVM || XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_RESTRICT __restrict
#	else
#		define XIEITE_RESTRICT
#	endif

#endif

// Thanks to eightfold for original code
// https://github.com/8ightfold
