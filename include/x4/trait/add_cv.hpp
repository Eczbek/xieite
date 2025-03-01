#pragma once

#include "../trait/addc.hpp"
#include "../trait/addv.hpp"

namespace x4 {
	template<typename T>
	using addcv = x4::add_c<x4::add_v<T>>;
}
