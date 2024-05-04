#ifndef XIEITE_HEADER_TRAITS_IS_RATIO
#	define XIEITE_HEADER_TRAITS_IS_RATIO

#	include <cstdint>
#	include <ratio>
#	include <type_traits>

namespace xieite::traits {
	template<typename>
	struct IsRatio
	: std::false_type {};

	template<std::intmax_t numerator_, std::intmax_t denominator_>
	struct IsRatio<std::ratio<numerator_, denominator_>>
	: std::true_type {};
}

#endif
