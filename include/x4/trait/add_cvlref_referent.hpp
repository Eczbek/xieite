#pragma once

#include "../trait/addcvreft.hpp"
#include "../trait/addlrefreft.hpp"

namespace x4 {
	template<typename T>
	using addcvlrefreft = x4::add_cvreft<x4::add_lrefreft<T>>;
}
