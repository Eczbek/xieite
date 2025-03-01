#pragma once

#include "../trait/rmvar.hpp"
#include "../trait/rmvrrefreft.hpp"

namespace x4 {
	template<typename T>
	using rmvarvrref = x4::rmvar<x4::rmvrrefreft<T>>;
}
