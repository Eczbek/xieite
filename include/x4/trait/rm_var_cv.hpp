#pragma once

#include "../trait/rmcvreft.hpp"
#include "../trait/rmvar.hpp"

namespace x4 {
	template<typename T>
	using rmvarcv = x4::rmvar<x4::rmcvreft<T>>;
}
