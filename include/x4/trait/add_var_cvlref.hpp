#pragma once

#include "../trait/addlrefreft.hpp"
#include "../trait/addvarcv.hpp"

namespace x4 {
	template<typename T>
	using addvarcvlref = x4::add_varcv<x4::add_lrefreft<T>>;
}
