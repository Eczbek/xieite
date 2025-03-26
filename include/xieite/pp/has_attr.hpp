#ifndef DETAIL_XIEITE_HEADER_PP_HAS_ATTR
#	define DETAIL_XIEITE_HEADER_PP_HAS_ATTR
#
#	include "../pp/compiler.hpp"
#	include "../pp/lang.hpp"
#
#	if XIEITE_LANG_LEAST(CPP, 2020)
#		define XIEITE_HAS_ATTR(...) __has_cpp_attribute(__VA_ARGS__)
#	elif XIEITE_LANG_LEAST(C, 2023)
#		define XIEITE_HAS_ATTR(...) __has_c_attribute(__VA_ARGS__)
#	elif XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_HAS_ATTR(...) __has_attribute(__VA_ARGS__)
#	else
#		define XIEITE_HAS_ATTR(...) 0
#	endif
#endif

// Thanks to Ian Pike (https://github.com/Rinzii) for original code
