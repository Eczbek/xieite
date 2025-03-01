#pragma once

#include "../trait/addrefreft.hpp"
#include "../trait/addvarcv.hpp"

namespace x4 {
	template<typename T, typename U>
	using addvarcvref = x4::add_varcv<x4::add_refreft<T, U>>;
}
