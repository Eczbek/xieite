#pragma once

#if defined(DEBUG) || !defined(NDEBUG) || defined(_DEBUG) || defined(QT_DEBUG)
#	define XIEITE_DEBUG 1
#else
#	define XIEITE_DEBUG 0
#endif
