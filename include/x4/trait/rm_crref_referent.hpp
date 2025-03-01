#pragma once

#include "../trait/rmcreft.hpp"
#include "../trait/rmrrefreft.hpp"

namespace x4 {
	template<typename T>
	using rmcrrefreft = x4::rmcreft<x4::rmrrefreft<T>>;
}
