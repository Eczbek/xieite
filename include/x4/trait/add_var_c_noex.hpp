#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvarc.hpp"

namespace x4 {
	template<typename T>
	using addvarcnoex = x4::add_varc<x4::addnoex<T>>;
}
