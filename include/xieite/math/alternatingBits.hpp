#ifndef XIEITE_HEADER__MATH__ALTERNATING_BITS
#	define XIEITE_HEADER__MATH__ALTERNATING_BITS

#	include <concepts>
#	include <limits>

namespace xieite::math {
	template<std::integral Integral>
	inline constexpr Integral alternatingBits = std::numeric_limits<Integral>::max() / 3;
}

#endif
