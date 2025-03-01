#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvrrefreft.hpp"

namespace x4 {
	template<typename T>
	using rmvrrefnoex = x4::rmvrrefreft<x4::rmnoex<T>>;
}
