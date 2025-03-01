#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvarc.hpp"

namespace x4 {
	template<typename T>
	concept isvarcnoex = x4::isvarc<T> && x4::isnoex<T>;
}
