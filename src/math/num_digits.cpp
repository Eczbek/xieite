export module xieite:num_digits;

import std;
import :abs;
import :neg;

export namespace xieite {
	template<std::integral T>
	[[nodiscard]] constexpr std::size_t num_digits(T value, std::type_identity_t<T> radix = 10) noexcept {
		if (!radix) {
			return 1;
		}
		if (radix == 1) {
			return static_cast<std::size_t>(xieite::abs(value));
		}
		if (std::signed_integral<T> && (radix == static_cast<T>(-1))) {
			return static_cast<std::size_t>(xieite::abs(value) * 2) + 1;
		}
		std::size_t result = 0;
		do {
			value = value / radix + xieite::neg(value % radix);
			++result;
		} while (value);
		return result;
	}
}
