#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvarrref.hpp"

namespace x4 {
	template<typename T>
	using rmvarrrefnoex = x4::rmvarrref<x4::rmnoex<T>>;
}
