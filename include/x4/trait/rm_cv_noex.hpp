#pragma once

#include "../trait/rmcvreft.hpp"
#include "../trait/rmnoex.hpp"

namespace x4 {
	template<typename T>
	using rmcvnoex = x4::rmcvreft<x4::rmnoex<T>>;
}
