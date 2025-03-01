#pragma once

#include "../trait/isrref.hpp"
#include "../trait/setrref.hpp"

namespace x4 {
	template<typename T, typename U>
	using cprref = x4::setrref<x4::isrref<T>, U>;
}
