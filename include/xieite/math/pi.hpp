#ifndef XIEITE_HEADER_MATH_PI
#	define XIEITE_HEADER_MATH_PI

#	include <concepts>
#	include <numbers>

namespace xieite::math {
	template<typename>
	inline constexpr double pi = std::numbers::pi;

	template<std::floating_point Fractional_>
	inline constexpr Fractional_ pi<Fractional_> = std::numbers::pi_v<Fractional_>;

	template<std::integral Integral_>
	inline constexpr Integral_ pi<Integral_> = static_cast<Integral_>(std::numbers::pi);
}

#endif
