#ifndef DETAIL_XTE_HEADER_PREPROC_FUNC_SIG
#	define DETAIL_XTE_HEADER_PREPROC_FUNC_SIG
#
#	include "../preproc/compiler.hpp"
#
#	if XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		define XTE_FUNC_SIG __PRETTY_FUNCTION__
#	elif XTE_COMPILER_MSVC
#		define XTE_FUNC_SIG __FUNCSIG__
#	else
#		define XTE_FUNC_SIG __func__
#	endif
#endif
