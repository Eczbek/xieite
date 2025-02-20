#pragma once

#include "../pp/cplr.hpp"

#if XIEITE_CPLR_TYPE_GCC || XIEITE_CPLR_TYPE_CLANG
#	define XIEITE_IS_CXPR(...) __builtin_constant_p(((void)(__VA_ARGS__), 0))
#else
#	define XIEITE_IS_CXPR(...) 0
#endif
