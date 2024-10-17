export module xieite:random.UniformDistribution;

import std;
import :concepts.Arithmetic;

export namespace xieite::random {
	template<xieite::concepts::Arithmetic Arithmetic>
	using UniformDistribution = std::conditional_t<std::floating_point<Arithmetic>, std::uniform_real_distribution<Arithmetic>, std::conditional_t<std::same_as<Arithmetic, bool>, std::bernoulli_distribution, std::uniform_int_distribution<Arithmetic>>>;
}

