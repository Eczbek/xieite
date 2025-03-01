#pragma once

#include "../trait/addrefreft.hpp"
#include "../trait/addvreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using addvrefreft = x4::add_vreft<x4::add_refreft<T, U>>;
}
