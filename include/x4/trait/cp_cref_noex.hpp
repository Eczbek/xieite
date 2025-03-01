#pragma once

#include "../trait/cpcrefreft.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcrefnoex = x4::cpcrefreft<T, x4::cpnoex<T, U>>;
}
