#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvreft.hpp"

namespace x4 {
	template<typename T>
	using addvnoex = x4::add_vreft<x4::addnoex<T>>;
}
