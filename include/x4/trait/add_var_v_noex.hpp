#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvarv.hpp"

namespace x4 {
	template<typename T>
	using addvarvnoex = x4::add_varv<x4::addnoex<T>>;
}
