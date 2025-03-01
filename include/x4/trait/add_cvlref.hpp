#pragma once

#include "../trait/addcv.hpp"
#include "../trait/addlref.hpp"

namespace x4 {
	template<typename T>
	using addcvlref = x4::add_cv<x4::add_lref<T>>;
}
