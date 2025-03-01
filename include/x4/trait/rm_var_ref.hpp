#pragma once

#include "../trait/rmrefreft.hpp"
#include "../trait/rmvar.hpp"

namespace x4 {
	template<typename T>
	using rmvarref = x4::rmvar<x4::rmrefreft<T>>;
}
