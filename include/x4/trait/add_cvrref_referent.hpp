#pragma once

#include "../trait/addcvreft.hpp"
#include "../trait/addrrefreft.hpp"

namespace x4 {
	template<typename T>
	using addcvrrefreft = x4::add_cvreft<x4::add_rrefreft<T>>;
}
