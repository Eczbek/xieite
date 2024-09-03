export module xieite:math.digits;

import std;
import :math.absolute;
import :math.isNegative;

export namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]] constexpr std::size_t digits(Integral value, const Integral radix = 10) noexcept {
		if (!radix) {
			return 1;
		}
		if (radix == 1) {
			return static_cast<std::size_t>(xieite::math::absolute(value));
		}
		if (std::signed_integral<Integral> && (radix == static_cast<Integral>(-1))) {
			return static_cast<std::size_t>(xieite::math::absolute(value) * 2) + 1;
		}
		std::size_t result = 0;
		do {
			value = value / radix + xieite::math::isNegative(value % radix);
			++result;
		} while (value);
		return result;
	}
}
