#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvarlref.hpp"

namespace x4 {
	template<typename T>
	using rmvarlrefnoex = x4::rmvarlref<x4::rmnoex<T>>;
}
