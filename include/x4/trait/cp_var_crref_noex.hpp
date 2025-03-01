#pragma once

#include "../trait/cpvarcrref.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarcrrefnoex = x4::cpvarcrref<T, x4::cpnoex<T, U>>;
}
