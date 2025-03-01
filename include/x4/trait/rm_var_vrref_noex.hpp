#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvarvrref.hpp"

namespace x4 {
	template<typename T>
	using rmvarvrrefnoex = x4::rmvarvrref<x4::rmnoex<T>>;
}
