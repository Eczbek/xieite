#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvrefreft.hpp"

namespace x4 {
	template<typename T>
	using rmvrefnoex = x4::rmvrefreft<x4::rmnoex<T>>;
}
