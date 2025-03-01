#pragma once

#include "../pp/cplr.hpp"
#include "../pp/lang.hpp"

#if X4LANGLEAST(C, 1999)
#	define X4RESTRICT restrict
#elif X4CPLR_GCC
#	define X4RESTRICT __restrict__
#elif X4CPLR_CLANG || X4CPLR_MSVC
#	define X4RESTRICT __restrict
#else
#	define X4RESTRICT
#endif
