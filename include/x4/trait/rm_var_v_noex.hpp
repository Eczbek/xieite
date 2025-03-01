#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvarv.hpp"

namespace x4 {
	template<typename T>
	using rmvarvnoex = x4::rmvarv<x4::rmnoex<T>>;
}
