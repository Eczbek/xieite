#ifndef XIEITE_HEADER_MATH_PI
#	define XIEITE_HEADER_MATH_PI

#	include <concepts>
#	include <numbers>

namespace xieite::math {
	template<typename>
	inline constexpr double pi = std::numbers::pi;

	template<std::floating_point FloatingPoint>
	inline constexpr FloatingPoint pi<FloatingPoint> = std::numbers::pi_v<FloatingPoint>;

	template<std::integral Integral>
	inline constexpr Integral pi<Integral> = static_cast<Integral>(std::numbers::pi);
}

// π

#endif
