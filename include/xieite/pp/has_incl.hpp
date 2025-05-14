#ifndef DETAIL_XIEITE_HEADER_PP_HAS_INCL
#	define DETAIL_XIEITE_HEADER_PP_HAS_INCL
#
#	include "../pp/lang.hpp"
#
#	if defined(__has_include) || XIEITE_LANG_VER(CPP, >=, 2017) || XIEITE_LANG_VER(C, >=, 2023)
#		define XIEITE_HAS_INCL(...) __has_include(__VA_ARGS__)
#	else
#		define XIEITE_HAS_INCL(...) 0
#	endif
#endif
