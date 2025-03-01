#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvarcrref.hpp"

namespace x4 {
	template<typename T>
	using addvarcrrefnoex = x4::add_varcrref<x4::addnoex<T>>;
}
