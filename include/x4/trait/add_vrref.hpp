#pragma once

#include "../trait/addrref.hpp"
#include "../trait/addv.hpp"

namespace x4 {
	template<typename T>
	using addvrref = x4::add_v<x4::add_rref<T>>;
}
