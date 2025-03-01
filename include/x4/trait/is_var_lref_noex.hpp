#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvarlref.hpp"

namespace x4 {
	template<typename T>
	concept isvarlrefnoex = x4::isvarlref<T> && x4::isnoex<T>;
}
