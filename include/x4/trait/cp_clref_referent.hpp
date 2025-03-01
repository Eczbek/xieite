#pragma once

#include "../trait/cpcreft.hpp"
#include "../trait/cplrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpclrefreft = x4::cpcreft<T, x4::cplrefreft<T, U>>;
}
