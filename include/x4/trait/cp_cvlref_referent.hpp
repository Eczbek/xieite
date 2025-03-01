#pragma once

#include "../trait/cpcvreft.hpp"
#include "../trait/cplrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcvlrefreft = x4::cpcvreft<T, x4::cplrefreft<T, U>>;
}
