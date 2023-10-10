#pragma once

#include "../macros/compiler.hpp"

#if XIEITE_COMPILER_GCC
#	define XIEITE_RESTRICT __restrict__
#elif XIEITE_COMPILER_LLVM || XIEITE_COMPILER_MSVC
#	define XIEITE_RESTRICT __restrict
#else
#	define XIEITE_RESTRICT
#endif

// Thanks to eightfold for original code
