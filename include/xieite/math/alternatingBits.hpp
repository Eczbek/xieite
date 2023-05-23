#ifndef XIEITE_HEADER_MATH_ALTERNATINGBITS
#	define XIEITE_HEADER_MATH_ALTERNATINGBITS

#	include <concepts>
#	include <limits>

namespace xieite::math {
	template<std::integral Integral>
	inline constexpr Integral alternatingBits = std::numeric_limits<Integral>::max() / 3;
}

#endif
