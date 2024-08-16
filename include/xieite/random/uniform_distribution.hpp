#ifndef XIEITE_HEADER_RANDOM_UNIFORM_DISTRIBUTION
#	define XIEITE_HEADER_RANDOM_UNIFORM_DISTRIBUTION

#	include <concepts>
#	include <random>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::random {
	template<xieite::concepts::Arithmetic Arithmetic>
	using UniformDistribution = std::conditional_t<std::integral<Arithmetic>, std::conditional_t<std::same_as<Arithmetic, bool>, std::bernoulli_distribution, std::uniform_int_distribution<Arithmetic>>, std::uniform_real_distribution<Arithmetic>>;
}

#endif
