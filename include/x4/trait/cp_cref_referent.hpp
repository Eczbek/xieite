#pragma once

#include "../trait/cpcreft.hpp"
#include "../trait/cprefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcrefreft = x4::cpcreft<T, x4::cprefreft<T, U>>;
}
