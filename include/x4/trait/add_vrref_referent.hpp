#pragma once

#include "../trait/addrrefreft.hpp"
#include "../trait/addvreft.hpp"

namespace x4 {
	template<typename T>
	using addvrrefreft = x4::add_vreft<x4::add_rrefreft<T>>;
}
