export module xieite:uniform_distr;

import std;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	using uniform_distr = std::conditional_t<std::floating_point<T>, std::uniform_real_distribution<T>, std::conditional_t<std::same_as<T, bool>, std::bernoulli_distribution, std::uniform_int_distribution<T>>>;
}

