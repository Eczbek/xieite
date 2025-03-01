#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvarvlref.hpp"

namespace x4 {
	template<typename T>
	using addvarvlrefnoex = x4::add_varvlref<x4::addnoex<T>>;
}
