export module xieite:math.reverse;

import std;
import :math.absolute;
import :math.isNegative;
import :math.sign;

export namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]] constexpr Integral reverse(Integral value, const Integral radix = 10) noexcept {
		const Integral sign = static_cast<Integral>(xieite::math::sign(value));
		value *= sign;
		Integral result = 0;
		while (value) {
			Integral digit = value % radix;
			value /= radix;
			if (xieite::math::isNegative(digit)) {
				digit += xieite::math::absolute(radix);
				++value;
			}
			result = result * radix + digit;
		}
		return result * sign;
	}
}
