export module xieite:math.sign;

import std;
import :concepts.Arithmetic;
import :math.isNegative;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic First, std::same_as<First>... Rest>
	[[nodiscard]] constexpr int sign(const First first, const Rest... rest) noexcept {
		static constexpr auto get = [](const First value) {
			return (value > 0) - xieite::math::isNegative(value);
		};
		return (get(first) * ... * get(rest));
	}
}
