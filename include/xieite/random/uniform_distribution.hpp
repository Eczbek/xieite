#ifndef XIEITE_HEADER_RANDOM_UNIFORM_DISTRIBUTION
#	define XIEITE_HEADER_RANDOM_UNIFORM_DISTRIBUTION

#	include <concepts>
#	include <random>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::random {
	template<xieite::concepts::Arithmetic Arithmetic_>
	using UniformDistribution = std::conditional_t<std::integral<Arithmetic_>, std::conditional_t<std::same_as<Arithmetic_, bool>, std::bernoulli_distribution, std::uniform_int_distribution<Arithmetic_>>, std::uniform_real_distribution<Arithmetic_>>;
}

#endif
