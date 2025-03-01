#pragma once

#include "../trait/addcvrrefreft.hpp"
#include "../trait/addnoex.hpp"

namespace x4 {
	template<typename T>
	using addcvrrefnoex = x4::add_cvrrefreft<x4::addnoex<T>>;
}
