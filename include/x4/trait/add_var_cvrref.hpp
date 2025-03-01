#pragma once

#include "../trait/addrrefreft.hpp"
#include "../trait/addvarcv.hpp"

namespace x4 {
	template<typename T>
	using addvarcvrref = x4::add_varcv<x4::add_rrefreft<T>>;
}
