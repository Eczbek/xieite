#pragma once

#include "../trait/rmcvrrefreft.hpp"
#include "../trait/rmvar.hpp"

namespace x4 {
	template<typename T>
	using rmvarcvrref = x4::rmvar<x4::rmcvrrefreft<T>>;
}
