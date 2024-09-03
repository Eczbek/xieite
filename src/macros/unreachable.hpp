#pragma once

#include "../macros/language_standard.hpp"

#if XIEITE_LANGUAGE_STANDARD_CPP_2023
#	include <utility>

#	define XIEITE_UNREACHABLE() (::std::unreachable())
#else
#	include "../macros/compiler.hpp"

#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_UNREACHABLE() __builtin_unreachable()
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_UNREACHABLE() __assume(false)
#	else
#		define XIEITE_UNREACHABLE() void(0 / 0)
#	endif
#endif

// Thanks to eightfold (https://github.com/8ightfold) for original code
