#pragma once

#include "../trait/rmc.hpp"
#include "../trait/rmref.hpp"

namespace x4 {
	template<typename T>
	using rmcref = x4::rmc<x4::rmref<T>>;
}
