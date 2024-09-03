export module xieite:math.isPrime;

import std;

export namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]] constexpr bool isPrime(const Integral value) noexcept {
		if constexpr (!std::same_as<Integral, bool>) {
			if (value < 4) {
				return value > 1;
			}
			if (!(value % 2) || !(value % 3)) {
				return false;
			}
			const Integral limit = std::sqrt(value);
			for (Integral i = 5; i <= limit; i += 6) {
				if (!(value % i) || !(value % (i + 2))) {
					return false;
				}
			}
		}
		return true;
	}
}
