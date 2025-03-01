#pragma once

#include "../trait/rmcreft.hpp"
#include "../trait/rmnoex.hpp"

namespace x4 {
	template<typename T>
	using rmcnoex = x4::rmcreft<x4::rmnoex<T>>;
}
