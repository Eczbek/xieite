#pragma once

#include <xieite/cplr.hpp>

#if XIEITE_CPLR_TYPE_GCC || XIEITE_CPLR_TYPE_CLANG
#	define XIEITE_FN_SIG __PRETTY_FUNCTION__
#elif XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_FN_SIG __FUNCSIG__
#else
#	define XIEITE_FN_SIG __func__
#endif
