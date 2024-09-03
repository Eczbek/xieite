export module xieite:math.pi;

import std;

export namespace xieite::math {
	template<typename>
	inline constexpr double pi = std::numbers::pi;

	template<std::floating_point Fractional>
	inline constexpr Fractional pi<Fractional> = std::numbers::pi_v<Fractional>;

	template<std::integral Integral>
	inline constexpr Integral pi<Integral> = static_cast<Integral>(std::numbers::pi);
}

// TODO: Remove `inline` once wreien fixes related bug next week
