#ifndef XIEITE_HEADER_RANDOM_UNIFORM_DISTRIBUTION
#	define XIEITE_HEADER_RANDOM_UNIFORM_DISTRIBUTION

#	include <concepts>
#	include <random>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::random {
	template<xieite::concepts::Arithmetic Number>
	using UniformDistribution = std::conditional_t<std::integral<Number>, std::conditional_t<std::same_as<Number, bool>, std::bernoulli_distribution, std::uniform_int_distribution<Number>>, std::uniform_real_distribution<Number>>;
}

#endif
