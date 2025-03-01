#pragma once

#include "../trait/addlref.hpp"
#include "../trait/addv.hpp"

namespace x4 {
	template<typename T>
	using addvlref = x4::add_v<x4::add_lref<T>>;
}
