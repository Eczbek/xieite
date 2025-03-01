#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvarvlref.hpp"

namespace x4 {
	template<typename T>
	using rmvarvlrefnoex = x4::rmvarvlref<x4::rmnoex<T>>;
}
