#pragma once

#include "../trait/cpvreft.hpp"
#include "../trait/cprrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvrrefreft = x4::cpvreft<T, x4::cprrefreft<T, U>>;
}
