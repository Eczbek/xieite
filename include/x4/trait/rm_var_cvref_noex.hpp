#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvarcvref.hpp"

namespace x4 {
	template<typename T>
	using rmvarcvrefnoex = x4::rmvarcvref<x4::rmnoex<T>>;
}
