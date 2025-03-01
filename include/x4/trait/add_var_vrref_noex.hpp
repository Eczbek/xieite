#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvarvrref.hpp"

namespace x4 {
	template<typename T>
	using addvarvrrefnoex = x4::add_varvrref<x4::addnoex<T>>;
}
