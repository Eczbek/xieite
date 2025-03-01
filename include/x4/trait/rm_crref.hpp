#pragma once

#include "../trait/rmc.hpp"
#include "../trait/rmrref.hpp"

namespace x4 {
	template<typename T>
	using rmcrref = x4::rmc<x4::rmrref<T>>;
}
