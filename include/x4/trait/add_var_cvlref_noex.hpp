#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvarcvlref.hpp"

namespace x4 {
	template<typename T>
	using addvarcvlrefnoex = x4::add_varcvlref<x4::addnoex<T>>;
}
