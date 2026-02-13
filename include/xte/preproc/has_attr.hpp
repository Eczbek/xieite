#ifndef DETAIL_XTE_HEADER_PREPROC_HAS_ATTR
#	define DETAIL_XTE_HEADER_PREPROC_HAS_ATTR
#
#	include "../preproc/compiler.hpp"
#	include "../preproc/lang.hpp"
#
#	if XTE_LANG(CPP, >=, 2020)
#		define XTE_HAS_ATTR(_attr) __has_cpp_attribute(_attr)
#	elif XTE_LANG(C, >=, 2023)
#		define XTE_HAS_ATTR(_attr) __has_c_attribute(_attr)
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		define XTE_HAS_ATTR(_attr) __has_attribute(_attr)
#	else
#		define XTE_HAS_ATTR(_attr) 0
#	endif
#endif
