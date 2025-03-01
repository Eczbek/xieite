#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvarlref.hpp"

namespace x4 {
	template<typename T>
	using addvarlrefnoex = x4::add_varlref<x4::addnoex<T>>;
}
