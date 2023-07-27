#ifndef XIEITE_HEADER_MATH_DIFFERENCE
#	define XIEITE_HEADER_MATH_DIFFERENCE

#	include <cmath>
#	include <concepts>
#	include <type_traits>

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]]
	constexpr std::make_unsigned_t<Integral> difference(const Integral a, const Integral b) noexcept {
		return ((a > b) ? (static_cast<std::make_unsigned_t<Integral>>(a) - static_cast<std::make_unsigned_t<Integral>>(b)) : (static_cast<std::make_unsigned_t<Integral>>(b) - static_cast<std::make_unsigned_t<Integral>>(a)));
	}

	template<std::floating_point FloatingPoint>
	[[nodiscard]]
	constexpr FloatingPoint difference(const FloatingPoint a, const FloatingPoint b) noexcept {
		return std::abs(a - b);
	}
}

#endif
