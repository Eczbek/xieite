#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvarcrref.hpp"

namespace x4 {
	template<typename T>
	concept isvarcrrefnoex = x4::isvarcrref<T> && x4::isnoex<T>;
}
