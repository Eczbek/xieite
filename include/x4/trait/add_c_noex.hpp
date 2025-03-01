#pragma once

#include "../trait/addcreft.hpp"
#include "../trait/addnoex.hpp"

namespace x4 {
	template<typename T>
	using addcnoex = x4::add_creft<x4::addnoex<T>>;
}
