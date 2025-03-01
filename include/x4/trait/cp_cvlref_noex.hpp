#pragma once

#include "../trait/cpcvlrefreft.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcvlrefnoex = x4::setcvlrefreft<T, x4::cpnoex<T, U>>;
}
