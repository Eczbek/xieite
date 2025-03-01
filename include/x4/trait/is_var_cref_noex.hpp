#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvarcref.hpp"

namespace x4 {
	template<typename T>
	concept isvarcrefnoex = x4::isvarcref<T> && x4::isnoex<T>;
}
