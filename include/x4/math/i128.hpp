#pragma once

#include "../pp/cplr.hpp"

#if X4CPLR_MSVC
#	include <__msvc_int128.hpp>
#elif !X4CPLR_GCC && !X4CPLR_CLANG
#	warning "unsupported compiler"
#endif

namespace x4 {
#if X4CPLR_MSVC
	using i128 = std::_Signed128;
	using u128 = std::_Unsigned128;
#else
	__extension__ using i128 = __int128;
	__extension__ using u128 = unsigned __int128;
#endif
}
