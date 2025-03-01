#pragma once

#include "../trait/rmcv.hpp"
#include "../trait/rmlref.hpp"

namespace x4 {
	template<typename T>
	using rmcvlref = x4::rmcv<x4::rmlref<T>>;
}
