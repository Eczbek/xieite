#pragma once

#include "../trait/addcv.hpp"
#include "../trait/addrref.hpp"

namespace x4 {
	template<typename T>
	using addcvrref = x4::add_cv<x4::add_rref<T>>;
}
