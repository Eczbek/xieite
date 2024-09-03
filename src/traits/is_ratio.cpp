export module xieite:traits.IsRatio;

import std;

export namespace xieite::traits {
	template<typename>
	struct IsRatio
	: std::false_type {};

	template<std::intmax_t numerator, std::intmax_t denominator>
	struct IsRatio<std::ratio<numerator, denominator>>
	: std::true_type {};
}
