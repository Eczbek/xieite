#pragma once

#include "../trait/cpvarcvref.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarcvrefnoex = x4::cpvarcvref<T, x4::cpnoex<T, U>>;
}
