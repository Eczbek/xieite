#ifndef XIEITE_HEADER__MACROS__FUNCTION_SIGNATURE
#	define XIEITE_HEADER__MACROS__FUNCTION_SIGNATURE

#	include "../macros/compiler_type.hpp"

#	if XIEITE__COMPILER_TYPE__GCC || XIEITE__COMPILER_TYPE__LLVM
#		define XIEITE__FUNCTION_SIGNATURE __PRETTY_FUNCTION__
#	elif XIEITE__COMPILER_TYPE__MSVC
#		define XIEITE__FUNCTION_SIGNATURE __FUNCSIG__
#	else
#		define XIEITE__FUNCTION_SIGNATURE __func__
#	endif

#endif

// Thanks to eightfold for original code
