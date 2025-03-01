#pragma once

#include "../trait/cplref.hpp"
#include "../trait/rmv.hpp"

namespace x4 {
	template<typename T>
	using rmvlref = x4::rmv<x4::rmlref<T>>;
}
