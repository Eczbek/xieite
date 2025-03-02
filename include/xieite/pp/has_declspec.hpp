#pragma once

#include "../pp/compiler.hpp"

#if XIEITE_COMPILER_TYPE_CLANG
#	ifdef __has_declspec_attribute
#		define XIEITE_HAS_DECLSPEC(...) __has_declspec_attribute(__VA_ARGS__)
#	else
#		define XIEITE_HAS_DECLSPEC(...) 0
#	endif
#elif XIEITE_COMPILER_TYPE_MSVC
#	define XIEITE_HAS_DECLSPEC(...) 1
#else
#	define XIEITE_HAS_DECLSPEC(...) 0
#endif

// Thanks to Ian Pike (https://github.com/Rinzii) for original code
