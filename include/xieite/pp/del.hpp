#ifndef DETAIL_XIEITE_HEADER_PP_DEL
#	define DETAIL_XIEITE_HEADER_PP_DEL
#
#	include "../pp/lang.hpp"
#
#	if XIEITE_LANG_VER(CPP, >=, 2026)
#		define XIEITE_DEL(s_) delete(s_)
#	else
#		define XIEITE_DEL(_) delete
#	endif
#endif
