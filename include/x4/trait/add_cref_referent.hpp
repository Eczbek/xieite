#pragma once

#include "../trait/addcreft.hpp"
#include "../trait/addrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using addcrefreft = x4::add_creft<x4::add_refreft<T, U>>;
}
