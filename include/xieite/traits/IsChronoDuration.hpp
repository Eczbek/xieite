#ifndef XIEITE_HEADER__TRAITS__IS_CHRONO_DURATION
#	define XIEITE_HEADER__TRAITS__IS_CHRONO_DURATION

#	include <chrono>
#	include <cstdint>
#	include <ratio>
#	include <type_traits>
#	include "../concepts/Arithmetic.hpp"

namespace xieite::traits {
	template<typename>
	struct IsChronoDuration
	: std::false_type {};

	template<xieite::concepts::Arithmetic Arithmetic, std::intmax_t numerator, std::intmax_t denominator>
	struct IsChronoDuration<std::chrono::duration<Arithmetic, std::ratio<numerator, denominator>>>
	: std::true_type {};
}

#endif
