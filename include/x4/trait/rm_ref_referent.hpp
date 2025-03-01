#pragma once

#include "../trait/rmlrefreft.hpp"
#include "../trait/rmrrefreft.hpp"

namespace x4 {
	template<typename T>
	using rmrefreft = x4::rmlrefreft<x4::rmrrefreft<T>>;
}
