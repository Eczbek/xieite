#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvarvref.hpp"

namespace x4 {
	template<typename T>
	using rmvarvrefnoex = x4::rmvarvref<x4::rmnoex<T>>;
}
