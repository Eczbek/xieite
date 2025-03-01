#pragma once

#include "../pp/cplr.hpp"

#if X4CPLR_GCC || X4CPLR_CLANG
#	define X4ISCXPR(...) __builtin_constant_p(((void)(__VA_ARGS__), 0))
#else
#	define X4ISCXPR(...) 0
#endif
