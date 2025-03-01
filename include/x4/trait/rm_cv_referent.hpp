#pragma once

#include "../trait/rmcreft.hpp"
#include "../trait/rmvreft.hpp"

namespace x4 {
	template<typename T>
	using rmcvreft = x4::rmcreft<x4::rmvreft<T>>;
}
