#pragma once

#include "../trait/cpcvreft.hpp"
#include "../trait/cprrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcvrrefreft = x4::cpcvreft<T, x4::cprrefreft<T, U>>;
}
