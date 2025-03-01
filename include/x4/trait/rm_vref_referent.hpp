#pragma once

#include "../trait/rmrefreft.hpp"
#include "../trait/rmvreft.hpp"

namespace x4 {
	template<typename T>
	using rmvrefreft = x4::rmvreft<x4::rmrefreft<T>>;
}
