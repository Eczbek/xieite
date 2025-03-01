#pragma once

#include <cstdint>
#include <ratio>
#include <type_traits>
#include "../trait/rmcv.hpp"

namespace x4 {
	template<typename T>
	concept isratio = requires { ([]<std::intmax_t numer, std::intmax_t denom>(std::type_identity<std::ratio<numer, denom>>) {})(std::type_identity<x4::rmcv<T>>()); };
}
