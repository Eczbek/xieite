#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvarref.hpp"

namespace x4 {
	template<typename T>
	concept isvarrefnoex = x4::isvarref<T> && x4::isnoex<T>;
}
