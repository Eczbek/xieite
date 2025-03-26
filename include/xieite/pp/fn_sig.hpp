#ifndef DETAIL_XIEITE_HEADER_PP_FN_SIG
#	define DETAIL_XIEITE_HEADER_PP_FN_SIG
#
#	include "../pp/compiler.hpp"
#
#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_FN_SIG __PRETTY_FUNCTION__
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_FN_SIG __FUNCSIG__
#	else
#		define XIEITE_FN_SIG __func__
#	endif
#endif
