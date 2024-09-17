export module xieite:math.pi;

import std;

export namespace xieite::math {
	template<typename>
	constexpr double pi = std::numbers::pi;

	template<std::floating_point Fractional>
	constexpr Fractional pi<Fractional> = std::numbers::pi_v<Fractional>;

	template<std::integral Integral>
	constexpr Integral pi<Integral> = static_cast<Integral>(std::numbers::pi);
}
