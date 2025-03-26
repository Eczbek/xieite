#ifndef DETAIL_XIEITE_HEADER_PP_DEBUG
#	define DETAIL_XIEITE_HEADER_PP_DEBUG
#
#	if defined(DEBUG) || !defined(NDEBUG) || defined(_DEBUG) || defined(QT_DEBUG)
#		define XIEITE_DEBUG 1
#	else
#		define XIEITE_DEBUG 0
#	endif
#endif
