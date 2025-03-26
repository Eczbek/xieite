#ifndef DETAIL_XIEITE_HEADER_PP_RESTRICT
#	define DETAIL_XIEITE_HEADER_PP_RESTRICT
#
#	include "../pp/compiler.hpp"
#	include "../pp/lang.hpp"
#
#	if XIEITE_LANG_LEAST(C, 1999)
#		define XIEITE_RESTRICT restrict
#	elif XIEITE_COMPILER_LEAST(GCC, 3)
#		define XIEITE_RESTRICT __restrict__
#	elif XIEITE_COMPILER_TYPE_CLANG || XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_RESTRICT __restrict
#	else
#		define XIEITE_RESTRICT
#	endif
#endif

// Thanks to eightfold (https://github.com/8ightfold) for original code
