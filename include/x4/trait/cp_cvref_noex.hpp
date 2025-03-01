#pragma once

#include "../trait/cpcvrefreft.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcvrefnoex = x4::setcvrefreft<T, x4::cpnoex<T, U>>;
}
