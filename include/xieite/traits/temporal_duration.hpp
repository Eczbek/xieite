#ifndef XIEITE_HEADER_TRAITS_TEMPORAL_DURATION
#	define XIEITE_HEADER_TRAITS_TEMPORAL_DURATION

#	include <chrono>
#	include <cstdint>
#	include <ratio>
#	include <type_traits>
#	include "../concepts/numeric.hpp"

namespace xieite::traits {
	template<typename>
	struct TemporalDuration
	: std::false_type {};

	template<xieite::concepts::Numeric Number, std::intmax_t numerator, std::intmax_t denominator>
	struct TemporalDuration<std::chrono::duration<Number, std::ratio<numerator, denominator>>>
	: std::true_type {};
}

#endif
