#pragma once

#include "../trait/rmrrefreft.hpp"
#include "../trait/rmnoex.hpp"

namespace x4 {
	template<typename T>
	using rmrrefnoex = x4::rmrrefreft<x4::rmnoex<T>>;
}
