export module xieite:pi;

import std;

export namespace xieite {
	template<typename>
	constexpr double pi = std::numbers::pi;

	template<std::floating_point T>
	constexpr T pi<T> = std::numbers::pi_v<T>;

	template<std::integral T>
	constexpr T pi<T> = static_cast<T>(std::numbers::pi);
}
