#pragma once

#include "../trait/addrefreft.hpp"
#include "../trait/addvarc.hpp"

namespace x4 {
	template<typename T, typename U>
	using addvarcref = x4::add_varc<x4::add_refreft<T, U>>;
}
