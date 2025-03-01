#pragma once

#include "../trait/cpvrefreft.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvrefnoex = x4::cpvrefreft<T, x4::cpnoex<T, U>>;
}
