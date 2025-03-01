#pragma once

#include "../trait/addcreft.hpp"
#include "../trait/addvreft.hpp"

namespace x4 {
	template<typename T>
	using addcvreft = x4::add_creft<x4::add_vreft<T>>;
}
