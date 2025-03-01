#pragma once

#include "../trait/rmcrefreft.hpp"
#include "../trait/rmvar.hpp"

namespace x4 {
	template<typename T>
	using rmvarcref = x4::rmvar<x4::rmcrefreft<T>>;
}
