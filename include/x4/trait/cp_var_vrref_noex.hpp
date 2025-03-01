#pragma once

#include "../trait/cpvarvrref.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarvrrefnoex = x4::cpvarvrref<T, x4::cpnoex<T, U>>;
}
