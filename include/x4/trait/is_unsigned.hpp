#pragma once

#include <concepts>
#include "../trait/rmcv.hpp"

namespace x4 {
	template<typename T>
	concept isunsigned = std::unsigned_integral<T> && !std::same_as<x4::rmcv<T>, bool>;
}
