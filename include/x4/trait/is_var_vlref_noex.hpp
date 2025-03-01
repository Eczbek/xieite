#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvarvlref.hpp"

namespace x4 {
	template<typename T>
	concept isvarvlrefnoex = x4::isvarvlref<T> && x4::isnoex<T>;
}
