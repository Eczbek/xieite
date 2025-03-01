#pragma once

#include "../trait/rmc.hpp"
#include "../trait/rmv.hpp"

namespace x4 {
	template<typename T>
	using rmcv = x4::rmc<x4::rmv<T>>;
}
