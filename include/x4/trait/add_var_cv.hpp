#pragma once

#include "../trait/addcvreft.hpp"
#include "../trait/addvar.hpp"

namespace x4 {
	template<typename T>
	using addvarcv = x4::add_var<x4::add_cvreft<T>>;
}
