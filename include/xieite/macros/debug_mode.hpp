#ifndef XIEITE_HEADER_MACROS_DEBUG_MODE
#	define XIEITE_HEADER_MACROS_DEBUG_MODE

#	if defined(DEBUG) || !defined(NDEBUG) || defined(_DEBUG) || defined(QT_DEBUG)
#		define XIEITE_DEBUG_MODE 1
#	else
#		define XIEITE_DEBUG_MODE 0
#	endif
#endif
