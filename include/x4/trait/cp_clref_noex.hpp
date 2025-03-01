#pragma once

#include "../trait/cpclrefreft.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpclrefnoex = x4::cpclrefreft<T, x4::cpnoex<T, U>>;
}
