#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvarclref.hpp"

namespace x4 {
	template<typename T>
	concept isvarclrefnoex = x4::isvarclref<T> && x4::isnoex<T>;
}
