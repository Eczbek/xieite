#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addrrefreft.hpp"

namespace x4 {
	template<typename T>
	using addrrefnoex = x4::add_rrefreft<x4::addnoex<T>>;
}
