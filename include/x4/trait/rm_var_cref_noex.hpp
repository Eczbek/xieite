#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvar.hpp"

namespace x4 {
	template<typename T>
	using rmvarcrefnoex = x4::rmvarcref<x4::rmnoex<T>>;
}
