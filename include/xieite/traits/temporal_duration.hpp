#ifndef XIEITE_HEADER_TRAITS_TEMPORAL_DURATION
#	define XIEITE_HEADER_TRAITS_TEMPORAL_DURATION

#	include <chrono>
#	include <type_traits>
#	include "../concepts/numeric.hpp"
#	include "../concepts/ratio.hpp"

namespace xieite::traits {
	template<
		typename
	> struct TemporalDuration
		: std::false_type
	{};

	template<
		xieite::concepts::Numeric Number,
		xieite::concepts::Ratio Ratio,
	> struct TemporalDuration<std::chrono::duration<Number, Ratio>>
		: std::true_type
	{};
}

#endif
