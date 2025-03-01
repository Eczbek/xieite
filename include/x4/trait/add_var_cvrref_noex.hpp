#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvarcvrref.hpp"

namespace x4 {
	template<typename T>
	using addvarcvrrefnoex = x4::add_varcvrref<x4::addnoex<T>>;
}
