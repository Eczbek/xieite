#pragma once

#include "../trait/rmcvrefreft.hpp"
#include "../trait/rmvar.hpp"

namespace x4 {
	template<typename T>
	using rmvarcvref = x4::rmvar<x4::rmcvrefreft<T>>;
}
