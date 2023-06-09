#ifndef XIEITE_HEADER_MATH_BITS
#	define XIEITE_HEADER_MATH_BITS

#	include <concepts>
#	include <cstddef>
#	include <limits>

namespace xieite::math {
	template<std::integral Integral>
	inline constexpr std::size_t bits = std::numeric_limits<Integral>::digits + std::numeric_limits<Integral>::is_signed;
}

#endif
