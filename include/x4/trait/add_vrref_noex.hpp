#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvrrefreft.hpp"

namespace x4 {
	template<typename T>
	using addvrrefnoex = x4::add_vrrefreft<x4::addnoex<T>>;
}
