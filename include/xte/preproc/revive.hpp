#ifndef DETAIL_XTE_HEADER_PREPROC_REVIVE
#	define DETAIL_XTE_HEADER_PREPROC_REVIVE
#
#	include "../preproc/pragma.hpp"
#
#	define XTE_REVIVE(M) XTE_PRAGMA(push_macro(#M)) XTE_PRAGMA(pop_macro(#M))
#endif
