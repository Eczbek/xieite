#pragma once

#include "../trait/rmcvlrefreft.hpp"
#include "../trait/rmnoex.hpp"

namespace x4 {
	template<typename T>
	using rmcvlrefnoex = x4::rmcvlrefreft<x4::rmnoex<T>>;
}
