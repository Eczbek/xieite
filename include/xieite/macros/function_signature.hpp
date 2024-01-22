#ifndef XIEITE_HEADER_MACROS_FUNCTION_SIGNATURE
#	define XIEITE_HEADER_MACROS_FUNCTION_SIGNATURE

#	include "../macros/compiler_type.hpp"

#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_LLVM
#		define XIEITE_FUNCTION_SIGNATURE __PRETTY_FUNCTION__
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_FUNCTION_SIGNATURE __FUNCSIG__
#	else
#		define XIEITE_FUNCTION_SIGNATURE __func__
#	endif

#endif

// Thanks to eightfold for original code
// https://github.com/8ightfold
