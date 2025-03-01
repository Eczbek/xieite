#pragma once

#include "../pp/lang.hpp"

#if X4LANGLEAST(CPP, 2023)
#	include <utility>

#	define X4UNREACH() (::std::unreachable())
#elif X4LANGLEAST(C, 2023)
#	include <stddef.h>

#	define X4UNREACH() (unreachable())
#else
#	include "../pp/cplr.hpp"

#	if X4CPLR_GCC || X4CPLR_CLANG
#		define X4UNREACH() (__builtin_unreachable())
#	elif X4CPLR_MSVC
#		define X4UNREACH() (__assume(false))
#	else
#		include "../pp/attr.hpp"

X4ATTR_NORET inline void DETAIL_X4unreach() {}

#		define X4UNREACH() (DETAIL_X4unreach())
#	endif
#endif
