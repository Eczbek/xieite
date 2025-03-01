#pragma once

#include "../trait/rmcvlrefreft.hpp"
#include "../trait/rmvar.hpp"

namespace x4 {
	template<typename T>
	using rmvarcvlref = x4::rmvar<x4::rmcvlrefreft<T>>;
}
