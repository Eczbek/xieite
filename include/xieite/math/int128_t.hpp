#pragma once

#include "../pp/cplr.hpp"

#if XIEITE_CPLR_TYPE_MSVC
#	include <__msvc_int128.hpp>
#elif !XIEITE_CPLR_TYPE_GCC && !XIEITE_CPLR_TYPE_CLANG
#	warning "unsupported compiler"
#endif

namespace xieite {
#if XIEITE_CPLR_TYPE_MSVC
	using int128_t = std::_Signed128;
	using uint128_t = std::_Unsigned128;
#else
	__extension__ using int128_t = __int128;
	__extension__ using uint128_t = unsigned __int128;
#endif
}
