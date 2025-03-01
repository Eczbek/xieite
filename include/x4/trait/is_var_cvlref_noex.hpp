#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvarcvlref.hpp"

namespace x4 {
	template<typename T>
	concept isvarcvlrefnoex = x4::isvarcvlref<T> && x4::isnoex<T>;
}
