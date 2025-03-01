#pragma once

#include "../trait/addc.hpp"
#include "../trait/addrref.hpp"

namespace x4 {
	template<typename T>
	using addcrref = x4::add_c<x4::add_rref<T>>;
}
