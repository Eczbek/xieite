#pragma once

#include "../trait/rmlrefreft.hpp"
#include "../trait/rmvreft.hpp"

namespace x4 {
	template<typename T>
	using rmvlrefreft = x4::rmvreft<x4::rmlrefreft<T>>;
}
