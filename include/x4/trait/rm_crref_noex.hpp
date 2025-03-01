#pragma once

#include "../trait/rmcrrefreft.hpp"
#include "../trait/rmnoex.hpp"

namespace x4 {
	template<typename T>
	using rmcrrefnoex = x4::rmcrrefreft<x4::rmnoex<T>>;
}
