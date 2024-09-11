export module xieite:concepts.Ratio;

import std;

template<typename>
struct IsRatio
: std::false_type {};

template<std::intmax_t numerator, std::intmax_t denominator>
struct IsRatio<std::ratio<numerator, denominator>>
: std::true_type {};

export namespace xieite::concepts {
	template<typename Type>
	concept Ratio = IsRatio<std::remove_cv_t<Type>>::value;
}
