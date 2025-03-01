#pragma once

#include "../trait/rmvar.hpp"
#include "../trait/rmvlrefreft.hpp"

namespace x4 {
	template<typename T>
	using rmvarvlref = x4::rmvar<x4::rmvlrefreft<T>>;
}
