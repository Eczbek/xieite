#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvarrref.hpp"

namespace x4 {
	template<typename T>
	concept isvarrrefnoex = x4::isvarrref<T> && x4::isnoex<T>;
}
