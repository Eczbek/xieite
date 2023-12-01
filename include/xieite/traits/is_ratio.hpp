#ifndef XIEITE_HEADER_TRAITS_IS_RATIO
#	define XIEITE_HEADER_TRAITS_IS_RATIO

#	include <cstdint>
#	include <ratio>
#	include <type_traits>

namespace xieite::traits {
	template<typename>
	struct IsRatio
	: std::false_type {};

	template<std::intmax_t numerator, std::intmax_t denominator>
	struct IsRatio<std::ratio<numerator, denominator>>
	: std::true_type {};
}

#endif
