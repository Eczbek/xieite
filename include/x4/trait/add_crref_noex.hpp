#pragma once

#include "../trait/addcrrefreft.hpp"
#include "../trait/addnoex.hpp"

namespace x4 {
	template<typename T>
	using addcrrefnoex = x4::add_crrefreft<x4::addnoex<T>>;
}
