#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvarref.hpp"

namespace x4 {
	template<typename T>
	using rmvarrefnoex = x4::rmvarref<x4::rmnoex<T>>;
}
