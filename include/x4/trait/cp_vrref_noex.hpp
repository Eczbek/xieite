#pragma once

#include "../trait/cpvrrefreft.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvrrefnoex = x4::cpvrrefreft<T, x4::cpnoex<T, U>>;
}
