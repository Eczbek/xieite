#pragma once

#if defined(DEBUG) || !defined(NDEBUG) || defined(_DEBUG) || defined(QT_DEBUG)
#	define X4DEBUG 1
#else
#	define X4DEBUG 0
#endif
