#pragma once

#include "../trait/rmcvrrefreft.hpp"
#include "../trait/rmnoex.hpp"

namespace x4 {
	template<typename T>
	using rmcvrrefnoex = x4::rmcvrrefreft<x4::rmnoex<T>>;
}
