#pragma once

#include "../trait/cpcvrrefreft.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcvrrefnoex = x4::setcvrrefreft<T, x4::cpnoex<T, U>>;
}
