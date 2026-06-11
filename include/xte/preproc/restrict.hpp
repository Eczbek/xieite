#ifndef DETAIL_XTE_HEADER_PREPROC_RESTRICT
#	define DETAIL_XTE_HEADER_PREPROC_RESTRICT
#
#	include "../preproc/compiler.hpp"
#	include "../preproc/lang.hpp"
#
#	if XTE_LANG(C, >=, 1999) && !XTE_LANG_CPP
#		define XTE_RESTRICT restrict
#	elif XTE_COMPILER(GCC, >=, 3)
#		define XTE_RESTRICT __restrict__
#	elif XTE_COMPILER_CLANG || XTE_COMPILER_MSVC
#		define XTE_RESTRICT __restrict
#	else
#		define XTE_RESTRICT
#	endif
#endif
