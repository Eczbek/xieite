#ifndef XIEITE_HEADER_MATH_ABSOLUTE
#	define XIEITE_HEADER_MATH_ABSOLUTE

#	include <cmath>
#	include <concepts>
#	include <limits>
#	include <type_traits>

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]]
	constexpr std::make_unsigned_t<Integral> absolute(const Integral value) noexcept {
		return ((value < 0) ? (std::numeric_limits<std::make_unsigned_t<Integral>>::max() - value + 1) : value);
	}

	template<std::floating_point FloatingPoint>
	[[nodiscard]]
	constexpr FloatingPoint absolute(const FloatingPoint value) noexcept {
		return std::abs(value);
	}
}

#endif
