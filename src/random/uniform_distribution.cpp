export module xieite:random.UniformDistribution;

import std;
import :concepts.Arithmetic;

export namespace xieite::random {
	template<xieite::concepts::Arithmetic Arithmetic>
	using UniformDistribution = std::conditional_t<std::integral<Arithmetic>, std::conditional_t<std::same_as<Arithmetic, bool>, std::bernoulli_distribution, std::uniform_int_distribution<Arithmetic>>, std::uniform_real_distribution<Arithmetic>>;
}

