#ifndef XIEITE_HEADER_TRAITS_IS_DURATION
#	define XIEITE_HEADER_TRAITS_IS_DURATION

#	include <chrono>
#	include <cstdint>
#	include <ratio>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::traits {
	template<typename>
	struct IsDuration
	: std::false_type {};

	template<xieite::concepts::Arithmetic Number, std::intmax_t numerator, std::intmax_t denominator>
	struct IsDuration<std::chrono::duration<Number, std::ratio<numerator, denominator>>>
	: std::true_type {};
}

#endif
