#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvar.hpp"

namespace x4 {
	template<typename T>
	concept isvarnoex = x4::isvar<T> && x4::isnoex<T>;
}
