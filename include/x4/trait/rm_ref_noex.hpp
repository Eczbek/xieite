#pragma once

#include "../trait/rmrefreft.hpp"
#include "../trait/rmnoex.hpp"

namespace x4 {
	template<typename T>
	using rmrefnoex = x4::rmrefreft<x4::rmnoex<T>>;
}
