#pragma once

#include <xieite/lang.hpp>

#if XIEITE_LANG_LEAST(CPP, 2023)
#	include <utility>

#	define XIEITE_UNREACH() (::std::unreachable())
#elif XIEITE_LANG_LEAST(C, 2023)
#	include <stddef.h>

#	define XIEITE_UNREACH() (unreachable())
#else
#	include <xieite/cplr.hpp>

#	if XIEITE_CPLR_TYPE_GCC || XIEITE_CPLR_TYPE_CLANG
#		define XIEITE_UNREACH() (__builtin_unreachable())
#	elif XIEITE_CPLR_TYPE_MSVC
#		define XIEITE_UNREACH() (__assume(false))
#	else
#		include <xieite/attr.hpp>

XIEITE_ATTR_NORET inline void XIEITE_DETAIL_unreach() {}

#		define XIEITE_UNREACH() (XIEITE_DETAIL_unreach())
#	endif
#endif

// Thanks to eightfold (https://github.com/8ightfold) for original code
