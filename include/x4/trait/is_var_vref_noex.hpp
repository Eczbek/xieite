#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvarvref.hpp"

namespace x4 {
	template<typename T>
	concept isvarvrefnoex = x4::isvarvref<T> && x4::isnoex<T>;
}
