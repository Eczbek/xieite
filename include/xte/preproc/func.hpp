#ifndef DETAIL_XTE_HEADER_PREPROC_FUNC
#	define DETAIL_XTE_HEADER_PREPROC_FUNC
#
#	include "../preproc/compiler.hpp"
#
#	if XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		define XTE_FUNC __PRETTY_FUNCTION__
#	elif XTE_COMPILER_MSVC
#		define XTE_FUNC __FUNCSIG__
#	else
#		define XTE_FUNC __func__
#	endif
#endif
