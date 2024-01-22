#ifndef XIEITE_HEADER_MACROS_ASSUME
#	define XIEITE_HEADER_MACROS_ASSUME

#	include "../macros/compiler_type.hpp"
#	include "../macros/language_standard.hpp"

#	if XIEITE_LANGUAGE_STANDARD_CPP_2023
#		define XIEITE_ASSUME(...) [[assume(__VA_ARGS__)]]
#	elif XIEITE_COMPILER_TYPE_GCC && (XIEITE_COMPILER_VERSION_MAJOR >= 12) && (XIEITE_COMPILER_VERSION_MINOR >= 1)
#		define XIEITE_ASSUME(...) __attribute__((assume(__VA_ARGS__)))
#	elif XIEITE_COMPILER_TYPE_CLANG && (XIEITE_COMPILER_VERSION_MAJOR >= 4)
#		define XIEITE_ASSUME(...) __builtin_assume(__VA_ARGS__)
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ASSUME(...) __assume(__VA_ARGS__)
#	else
#		define XIEITE_ASSUME(...)
#	endif

#endif

// Thanks to Ian Pike for original code
// https://github.com/Rinzii
