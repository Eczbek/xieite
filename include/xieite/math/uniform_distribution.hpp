#ifndef DETAIL_XIEITE_HEADER_MATH_UNIFORM_DISTRIBUTION
#	define DETAIL_XIEITE_HEADER_MATH_UNIFORM_DISTRIBUTION
#
#	include <concepts>
#	include <random>
#	include <type_traits>
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	using uniform_distribution = std::conditional_t<std::floating_point<Arith>, std::uniform_real_distribution<Arith>, std::conditional_t<std::same_as<Arith, bool>, std::bernoulli_distribution, std::uniform_int_distribution<Arith>>>;
}

#endif
