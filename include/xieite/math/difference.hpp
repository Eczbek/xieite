#ifndef XIEITE_HEADER_MATH_DIFFERENCE
#	define XIEITE_HEADER_MATH_DIFFERENCE

#	include <cmath>
#	include <concepts>
#	include <type_traits>

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]]
	constexpr std::make_unsigned_t<Integral> difference(const Integral a, const Integral b) noexcept {
		const auto a2 = static_cast<std::make_unsigned_t<Integral>>(a);
		const auto b2 = static_cast<std::make_unsigned_t<Integral>>(b);
		return (a > b) ? (a2 - b2) : (b2 - a2);
	}

	template<std::floating_point FloatingPoint>
	[[nodiscard]]
	constexpr FloatingPoint difference(const FloatingPoint a, const FloatingPoint b) noexcept {
		return std::abs(a - b);
	}
}

#endif
