#pragma once

#include "../trait/rmcv.hpp"
#include "../trait/rmref.hpp"

namespace x4 {
	template<typename T>
	using rmcvref = x4::rmcv<x4::rmref<T>>;
}
