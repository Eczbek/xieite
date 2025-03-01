#pragma once

#include "../trait/rmrrefreft.hpp"
#include "../trait/rmvreft.hpp"

namespace x4 {
	template<typename T>
	using rmvrrefreft = x4::rmvreft<x4::rmrrefreft<T>>;
}
