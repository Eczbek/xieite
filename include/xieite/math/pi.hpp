#ifndef XIEITE_HEADER__MATH__PI
#	define XIEITE_HEADER__MATH__PI

#	include <concepts>
#	include <numbers>

namespace xieite::math {
	template<typename>
	inline constexpr double pi = std::numbers::pi;

	template<std::floating_point Floating>
	inline constexpr Floating pi<Floating> = std::numbers::pi_v<Floating>;

	template<std::integral Integer>
	inline constexpr Integer pi<Integer> = static_cast<Integer>(std::numbers::pi);
}

// π

#endif
