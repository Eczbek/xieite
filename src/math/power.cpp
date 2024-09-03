export module xieite:math.power;

import std;

export namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]] constexpr Integral power(Integral base, std::size_t exponent) noexcept {
		Integral result = 1;
		while (exponent) {
			if (exponent & 1) {
				result *= base;
			}
			exponent >>= 1;
			base *= base;
		}
		return result;
	}
}
