#ifndef DETAIL_XIEITE_HEADER_PP_REVIVE
#	define DETAIL_XIEITE_HEADER_PP_REVIVE
#
#	include "../pp/pragma.hpp"
#
#	define XIEITE_REVIVE(_fn) XIEITE_PRAGMA(push_macro(#_fn)) XIEITE_PRAGMA(pop_macro(#_fn))
#endif
