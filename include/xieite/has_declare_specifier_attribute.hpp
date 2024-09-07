#pragma once

#include <xieite/compiler.hpp>

#if XIEITE_COMPILER_TYPE_CLANG
#	ifdef __has_declspec_attribute
#		define XIEITE_HAS_DECLARE_SPECIFIER_ATTRIBUTE(...) __has_declspec_attribute(__VA_ARGS__)
#	else
#		define XIEITE_HAS_DECLARE_SPECIFIER_ATTRIBUTE(...) 0
#	endif
#elif XIEITE_COMPILER_TYPE_MSVC
#	define XIEITE_HAS_DECLARE_SPECIFIER_ATTRIBUTE(...) 1
#else
#	define XIEITE_HAS_DECLARE_SPECIFIER_ATTRIBUTE(...) 0
#endif

// Thanks to Ian Pike (https://github.com/Rinzii) for original code
