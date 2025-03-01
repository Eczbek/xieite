#pragma once

#include "../trait/addcvreft.hpp"
#include "../trait/addrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using addcvrefreft = x4::add_cvreft<x4::add_refreft<T, U>>;
}
