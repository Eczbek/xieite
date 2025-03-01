#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvarvrref.hpp"

namespace x4 {
	template<typename T>
	concept isvarvrrefnoex = x4::isvarvrref<T> && x4::isnoex<T>;
}
