#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvlrefreft.hpp"

namespace x4 {
	template<typename T>
	using addvlrefnoex = x4::add_vlrefreft<x4::addnoex<T>>;
}
