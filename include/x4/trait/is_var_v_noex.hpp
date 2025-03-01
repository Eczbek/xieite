#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvarv.hpp"

namespace x4 {
	template<typename T>
	concept isvarvnoex = x4::isvarv<T> && x4::isnoex<T>;
}
