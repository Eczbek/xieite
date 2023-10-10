#pragma once

#include "../macros/compiler.hpp"

#if XIEITE_COMPILER_GCC || XIEITE_COMPILER_LLVM
#	define XIEITE_FUNCTION_SIGNATURE __PRETTY_FUNCTION__
#elif XIEITE_COMPILER_MSVC
#	define XIEITE_FUNCTION_SIGNATURE __FUNCSIG__
#else
#	define XIEITE_FUNCTION_SIGNATURE __func__
#endif

// Thanks to eightfold for original code
