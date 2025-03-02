#pragma once

#include "../pp/lang.hpp"

#if XIEITE_LANG_LEAST(CPP, 2023)
#	include <utility>

#	define XIEITE_UNREACH() (::std::unreachable())
#elif XIEITE_LANG_LEAST(C, 2023)
#	include <stddef.h>

#	define XIEITE_UNREACH() (unreachable())
#else
#	include "../pp/compiler.hpp"

#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_UNREACH() (__builtin_unreachable())
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_UNREACH() (__assume(false))
#	else
#		include "../pp/attr.hpp"

XIEITE_ATTR_NORET inline void DETAIL_XIEITE_unreach() {}

#		define XIEITE_UNREACH() (DETAIL_XIEITE_unreach())
#	endif
#endif

// Thanks to eightfold (https://github.com/8ightfold) for original code
