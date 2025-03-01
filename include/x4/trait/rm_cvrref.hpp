#pragma once

#include "../trait/rmcv.hpp"
#include "../trait/rmrref.hpp"

namespace x4 {
	template<typename T>
	using rmcvrref = x4::rmcv<x4::rmrref<T>>;
}
