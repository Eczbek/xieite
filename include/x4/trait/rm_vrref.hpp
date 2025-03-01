#pragma once

#include "../trait/rmrref.hpp"
#include "../trait/rmv.hpp"

namespace x4 {
	template<typename T>
	using rmvrref = x4::rmv<x4::rmrref<T>>;
}
