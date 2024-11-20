#pragma once

#include <xieite/cplr.hpp>

#if XIEITE_CPLR_TYPE_GCC || XIEITE_CPLR_TYPE_CLANG
#	define XIEITE_IS_CONST(...) __builtin_constant_p(((void)(__VA_ARGS__), 0))
#else
#	define XIEITE_IS_CONST(...) 0
#endif
