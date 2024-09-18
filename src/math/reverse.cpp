export module xieite:math.reverse;

import std;
import :math.absolute;
import :math.isNegative;
import :math.TryUnsigned;

export namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]] constexpr Integral reverse(Integral value, const std::common_type_t<Integral> radix = 10) noexcept {
		if (!radix) {
			return 0;
		} else if ((radix == 1) || (!std::unsigned_integral<Integral> && (radix == static_cast<Integral>(-1)))) {
			return value;
		}
		const bool negative = xieite::math::isNegative(value);
		Integral result = 0;
		const auto nextDigit = [&value, radix, &result](Integral digit) {
			value /= radix;
			if (xieite::math::isNegative(digit)) {
				digit = xieite::math::isNegative(radix) ? (digit - radix) : (digit + radix);
				++value;
			}
			result = result * radix + digit;
		};
		if (value == std::numeric_limits<Integral>::min()) {
			nextDigit(-(value % radix));
		}
		value = static_cast<Integral>(xieite::math::absolute(value));
		while (value) {
			nextDigit(value % radix);
		}
		return negative ? -result : result;
	}
}
