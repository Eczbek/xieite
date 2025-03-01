#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvarcvrref.hpp"

namespace x4 {
	template<typename T>
	concept isvarcvrrefnoex = x4::isvarcvrref<T> && x4::isnoex<T>;
}
