#ifndef XIEITE_HEADER_TRAITS_ISTEMPORALDURATION
#	define XIEITE_HEADER_TRAITS_ISTEMPORALDURATION

#	include <chrono>
#	include <cstdint>
#	include <ratio>
#	include "../concepts/Arithmetic.hpp"

namespace xieite::traits {
	template<typename>
	inline constexpr bool isTemporalDuration = false;

	template<xieite::concepts::Arithmetic Arithmetic, std::intmax_t numerator, std::intmax_t denominator>
	inline constexpr bool isTemporalDuration<std::chrono::duration<Arithmetic, std::ratio<numerator, denominator>>> = true;
}

#endif
