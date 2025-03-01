#pragma once

#include "../pp/cplr.hpp"

#if X4CPLR_GCC || X4CPLR_CLANG
#	define X4FNSIG __PRETTY_FUNCTION__
#elif X4CPLR_MSVC
#	define X4FNSIG __FUNCSIG__
#else
#	define X4FNSIG __func__
#endif
