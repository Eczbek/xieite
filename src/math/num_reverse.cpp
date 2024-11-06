export module xieite:num_reverse;

import std;
import :abs;
import :neg;

export namespace xieite {
	template<std::integral T>
	[[nodiscard]] constexpr T num_reverse(T value, std::type_identity_t<T> radix = 10) noexcept {
		if (!radix) {
			return 0;
		} else if ((radix == 1) || (!std::unsigned_integral<T> && (radix == static_cast<T>(-1)))) {
			return value;
		}
		const bool neg = xieite::neg(value);
		T result = 0;
		const auto next = [&value, radix, &result](T digit) -> void {
			value /= radix;
			if (xieite::neg(digit)) {
				digit = xieite::neg(radix) ? (digit - radix) : (digit + radix);
				++value;
			}
			result = result * radix + digit;
		};
		if (value == std::numeric_limits<T>::min()) {
			next(-(value % radix));
		}
		value = static_cast<T>(xieite::abs(value));
		while (value) {
			next(value % radix);
		}
		return neg ? -result : result;
	}
}
