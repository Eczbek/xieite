#ifndef DETAIL_XIEITE_HEADER_PP_PRAGMA
#	define DETAIL_XIEITE_HEADER_PP_PRAGMA
#
#	include "../pp/compiler.hpp"
#	include "../pp/lang.hpp"
#	include "../pp/str.hpp"
#
#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG || XIEITE_LANG_VER(CPP, >=, 2011) || XIEITE_LANG_VER(C, >=, 1999)
#		define XIEITE_PRAGMA(...) _Pragma(XIEITE_STR(__VA_ARGS__))
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_PRAGMA(...) __pragma(__VA_ARGS__)
#	else
#		define XIEITE_PRAGMA(...)
#	endif
#endif
