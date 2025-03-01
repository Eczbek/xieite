#pragma once

#include "../trait/cpcreft.hpp"
#include "../trait/cprrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcrrefreft = x4::cpcreft<T, x4::cprrefreft<T, U>>;
}
