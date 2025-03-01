#pragma once

#include "../trait/rmcvreft.hpp"
#include "../trait/rmlrefreft.hpp"

namespace x4 {
	template<typename T>
	using rmcvlrefreft = x4::rmcvreft<x4::rmlrefreft<T>>;
}
