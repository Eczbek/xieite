#pragma once

#include <xieite/compiler.hpp>

#if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#	define XIEITE_IS_CONSTANT(...) __builtin_constant_p((void(__VA_ARGS__), 0))
#else
#	define XIEITE_IS_CONSTANT(...) 0
#endif
