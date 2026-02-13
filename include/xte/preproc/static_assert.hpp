#ifndef DETAIL_XTE_HEADER_PREPROC_STATIC_ASSERT
#	define DETAIL_XTE_HEADER_PREPROC_STATIC_ASSERT
#
#	include "../preproc/compiler.hpp"
#	include "../preproc/lang.hpp"
#
#	if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#		define XTE_STATIC_ASSERT(...) static_assert(__VA_ARGS__)
#	elif XTE_LANG(C, >=, 2011)
#		define XTE_STATIC_ASSERT(...) _Static_assert(__VA_ARGS__)
#	elif XTE_COMPILER_MSVC
#		include <crtdbg.h>
#		define XTE_STATIC_ASSERT(...) _STATIC_ASSERT(__VA_ARGS__)
#	else
#		define XTE_STATIC_ASSERT(_cond) typedef int XTE_STATIC_ASSERT[!(_cond) * -2 + 1]
#	endif
#endif
