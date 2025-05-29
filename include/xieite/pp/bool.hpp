#ifndef DETAIL_XIEITE_HEADER_PP_BOOL
#	define DETAIL_XIEITE_HEADER_PP_BOOL
#
#	include "../pp/compl.hpp"
#	include "../pp/not.hpp"
#
#	define XIEITE_BOOL(_x) XIEITE_COMPL(XIEITE_NOT(_x))
#endif
