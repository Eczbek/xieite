#pragma once

#include "../trait/addrefreft.hpp"
#include "../trait/addvar.hpp"

namespace x4 {
	template<typename T, typename U>
	using addvarref = x4::add_var<x4::add_refreft<T, U>>;
}
