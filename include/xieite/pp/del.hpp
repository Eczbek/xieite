#ifndef DETAIL_XIEITE_HEADER_PP_DEL
#	define DETAIL_XIEITE_HEADER_PP_DEL
#
#	include "../pp/lang.hpp"
#
#	if XIEITE_LANG_VER(CPP, >=, 2026)
#		define XIEITE_DEL(_msg) delete(_msg)
#	else
#		define XIEITE_DEL(_msg) delete
#	endif
#endif
