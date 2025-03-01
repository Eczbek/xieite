#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvarcvlref.hpp"

namespace x4 {
	template<typename T>
	using rmvarcvlrefnoex = x4::rmvarcvlref<x4::rmnoex<T>>;
}
