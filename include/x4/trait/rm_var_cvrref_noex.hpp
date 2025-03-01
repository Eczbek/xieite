#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvarcvrref.hpp"

namespace x4 {
	template<typename T>
	using rmvarcvrrefnoex = x4::rmvarcvrref<x4::rmnoex<T>>;
}
