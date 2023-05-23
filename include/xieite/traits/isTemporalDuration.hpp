#ifndef XIEITE_HEADER_TRAITS_ISTEMPORALDURATION
#	define XIEITE_HEADER_TRAITS_ISTEMPORALDURATION

#	include <chrono>
#	include <cstdint>
#	include <ratio>
#	include <xieite/concepts/Arithmetic.hpp>

namespace xieite::traits {
	template<typename>
	inline constexpr bool isTemporalDuration = false;

	template<xieite::concepts::Arithmetic Number, std::intmax_t numerator, std::intmax_t denominator>
	inline constexpr bool isTemporalDuration<std::chrono::duration<Number, std::ratio<numerator, denominator>>> = true;
}

#endif
