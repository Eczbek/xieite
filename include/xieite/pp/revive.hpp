#ifndef DETAIL_XIEITE_HEADER_PP_REVIVE
#	define DETAIL_XIEITE_HEADER_PP_REVIVE
#
#	include "../pp/pragma.hpp"
#
#	define XIEITE_REVIVE(f) XIEITE_PRAGMA(push_macro(#f)) XIEITE_PRAGMA(pop_macro(#f))
#endif
