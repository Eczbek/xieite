#pragma once

#include "../trait/rmvar.hpp"
#include "../trait/rmcrrefreft.hpp"

namespace x4 {
	template<typename T>
	using rmvarcrref = x4::rmvar<x4::rmcrrefreft<T>>;
}
