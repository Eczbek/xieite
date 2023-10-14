#ifndef XIEITE_HEADER_TRAITS_RATIO
#	define XIEITE_HEADER_TRAITS_RATIO

#	include <cstdint>
#	include <ratio>
#	include <type_traits>

namespace xieite::traits {
	template<typename>
	struct Ratio
	: std::false_type {};

	template<std::intmax_t numerator, std::intmax_t denominator>
	struct Ratio<std::ratio<numerator, denominator>>
	: std::true_type {};
}

#endif
