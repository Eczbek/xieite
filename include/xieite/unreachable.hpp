#pragma once

#include <xieite/lang.hpp>

#if XIEITE_LANG_LEAST(CPP, 2023)
#	include <utility>

#	define XIEITE_UNREACHABLE() ::std::unreachable()
#else
#	include <xieite/cplr.hpp>

#	if XIEITE_CPLR_TYPE_GCC || XIEITE_CPLR_TYPE_CLANG
#		define XIEITE_UNREACHABLE() __builtin_unreachable()
#	elif XIEITE_CPLR_TYPE_MSVC
#		define XIEITE_UNREACHABLE() __assume(false)
#	else
#		define XIEITE_UNREACHABLE() void(0 / 0)
#	endif
#endif

// Thanks to eightfold (https://github.com/8ightfold) for original code
