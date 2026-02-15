#ifndef DETAIL_XTE_HEADER_PREPROC_HAS_BUILTIN
#	define DETAIL_XTE_HEADER_PREPROC_HAS_BUILTIN
#
#	include "../preproc/compiler.hpp"
#
#	if XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		define XTE_HAS_BUILTIN(_name) __has_builtin(__builtin_##_name)
#	else
#		define XTE_HAS_BUILTIN(_name) 0
#	endif
#endif
