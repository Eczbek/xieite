#pragma once

#include "../trait/rmcvreft.hpp"
#include "../trait/rmrefreft.hpp"

namespace x4 {
	template<typename T>
	using rmcvrefreft = x4::rmcvreft<x4::rmrefreft<T>>;
}
