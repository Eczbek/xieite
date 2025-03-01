#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvlrefreft.hpp"

namespace x4 {
	template<typename T>
	using rmvlrefnoex = x4::rmvlrefreft<x4::rmnoex<T>>;
}
