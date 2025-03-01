#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvarcvref.hpp"

namespace x4 {
	template<typename T>
	concept isvarcvrefnoex = x4::isvarcvref<T> && x4::isnoex<T>;
}
