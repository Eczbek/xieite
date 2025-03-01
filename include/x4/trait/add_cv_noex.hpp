#pragma once

#include "../trait/addcvreft.hpp"
#include "../trait/addnoex.hpp"

namespace x4 {
	template<typename T>
	using addcvnoex = x4::add_cvreft<x4::addnoex<T>>;
}
