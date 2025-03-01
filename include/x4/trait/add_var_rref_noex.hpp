#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvarrref.hpp"

namespace x4 {
	template<typename T>
	using addvarrrefnoex = x4::add_varrref<x4::addnoex<T>>;
}
