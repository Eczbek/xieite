#pragma once

#include "../trait/rmcrefreft.hpp"
#include "../trait/rmnoex.hpp"

namespace x4 {
	template<typename T>
	using rmcrefnoex = x4::rmcrefreft<x4::rmnoex<T>>;
}
