#pragma once

#include "../trait/rmlrefreft.hpp"
#include "../trait/rmnoex.hpp"

namespace x4 {
	template<typename T>
	using rmlrefnoex = x4::rmlrefreft<x4::rmnoex<T>>;
}
