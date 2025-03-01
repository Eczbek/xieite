#pragma once

#include "../trait/addlrefreft.hpp"
#include "../trait/addvreft.hpp"

namespace x4 {
	template<typename T>
	using addvlrefreft = x4::add_vreft<x4::add_lrefreft<T>>;
}
