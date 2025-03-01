#pragma once

#include <concepts>
#include <random>
#include <type_traits>
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	using uniformdistr = std::conditional_t<std::floating_point<T>, std::uniform_real_distribution<T>, std::conditional_t<std::same_as<T, bool>, std::bernoulli_distribution, std::uniform_int_distribution<T>>>;
}

