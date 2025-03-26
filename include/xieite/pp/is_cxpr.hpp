#ifndef DETAIL_XIEITE_HEADER_PP_IS_CXPR
#	define DETAIL_XIEITE_HEADER_PP_IS_CXPR
#
#	include "../pp/compiler.hpp"
#
#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_IS_CXPR(...) __builtin_constant_p(((void)(__VA_ARGS__), 0))
#	else
#		define XIEITE_IS_CXPR(...) 0
#	endif
#endif
