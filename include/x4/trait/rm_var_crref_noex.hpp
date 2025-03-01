#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvarcrref.hpp"

namespace x4 {
	template<typename T>
	using rmvarcrrefnoex = x4::rmvarcrref<x4::rmnoex<T>>;
}
