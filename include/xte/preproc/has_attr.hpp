#ifndef DETAIL_XTE_HEADER_PREPROC_HAS_ATTR
#	define DETAIL_XTE_HEADER_PREPROC_HAS_ATTR
#
#	include "../preproc/compiler.hpp"
#	include "../preproc/lang.hpp"
#
#	if XTE_LANG(CPP, >=, 2020)
#		define XTE_HAS_ATTR(NAME) __has_cpp_attribute(NAME)
#	elif XTE_LANG(C, >=, 2023)
#		define XTE_HAS_ATTR(NAME) __has_c_attribute(NAME)
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		define XTE_HAS_ATTR(NAME) __has_attribute(NAME)
#	else
#		define XTE_HAS_ATTR(NAME) 0
#	endif
#endif
