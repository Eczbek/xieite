#pragma once

#include "../trait/cpvarref.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarrefnoex = x4::cpvarref<T, x4::cpnoex<T, U>>;
}
