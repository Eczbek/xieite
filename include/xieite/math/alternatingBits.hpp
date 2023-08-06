#ifndef XIEITE_HEADER__MATH__ALTERNATING_BITS
#	define XIEITE_HEADER__MATH__ALTERNATING_BITS

#	include <concepts>
#	include <limits>

namespace xieite::math {
	template<std::integral Integer>
	inline constexpr Integer alternatingBits = std::numeric_limits<Integer>::max() / 3;
}

#endif
