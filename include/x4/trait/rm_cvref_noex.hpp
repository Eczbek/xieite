#pragma once

#include "../trait/rmcvrefreft.hpp"
#include "../trait/rmnoex.hpp"

namespace x4 {
	template<typename T>
	using rmcvrefnoex = x4::rmcvrefreft<x4::rmnoex<T>>;
}
