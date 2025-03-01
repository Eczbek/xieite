#pragma once

#include "../trait/rmref.hpp"
#include "../trait/rmv.hpp"

namespace x4 {
	template<typename T>
	using rmvref = x4::rmv<x4::rmref<T>>;
}
