#pragma once

#include "../trait/cpcvreft.hpp"
#include "../trait/cprefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcvrefreft = x4::cpcvreft<T, x4::cprefreft<T, U>>;
}
