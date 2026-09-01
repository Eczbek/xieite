#ifndef DETAIL_XTE_HEADER_PREPROC_HAS_INCLUDE
#	define DETAIL_XTE_HEADER_PREPROC_HAS_INCLUDE
#
#	ifdef __has_include
#		define XTE_HAS_INCLUDE(INCLUDE) __has_include(INCLUDE)
#	else
#		define XTE_HAS_INCLUDE(INCLUDE) 0
#	endif
#endif
