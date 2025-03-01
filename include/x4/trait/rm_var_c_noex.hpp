#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvarc.hpp"

namespace x4 {
	template<typename T>
	using rmvarcnoex = x4::rmvarc<x4::rmnoex<T>>;
}
