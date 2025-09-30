#ifndef DETAIL_XTE_HEADER_PREPROC_HAS_INCLUDE
#	define DETAIL_XTE_HEADER_PREPROC_HAS_INCLUDE
#
#	include "../preproc/lang.hpp"
#
#	if defined(__has_include) || XTE_LANG_VERSION(CPP, >=, 2017) || XTE_LANG_VERSION(C, >=, 2023)
#		define XTE_HAS_INCLUDE(...) __has_include(__VA_ARGS__)
#	else
#		define XTE_HAS_INCLUDE(...) 0
#	endif
#endif
