#ifndef DETAIL_XIEITE_HEADER_PP_STATIC_ASSERT
#	define DETAIL_XIEITE_HEADER_PP_STATIC_ASSERT
#
#	include "../pp/compiler.hpp"
#	include "../pp/lang.hpp"
#
#	if XIEITE_LANG_LEAST(CPP, 2011) || XIEITE_LANG_LEAST(C, 2023)
#		define XIEITE_STATIC_ASSERT(...) static_assert(__VA_ARGS__)
#	elif XIEITE_LANG_LEAST(C, 2011)
#		define XIEITE_STATIC_ASSERT(...) _Static_assert(__VA_ARGS__)
#	elif XIEITE_COMPILER_TYPE_MSVC
#		include <crtdbg.h>
#		define XIEITE_STATIC_ASSERT(...) _STATIC_ASSERT(__VA_ARGS__)
#	else
#		define XIEITE_STATIC_ASSERT(...)
#	endif
#endif

// https://github.com/isar/libmdbx/blob/master/src/preface.h
