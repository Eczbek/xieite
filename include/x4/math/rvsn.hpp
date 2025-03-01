#pragma once

#include <concepts>
#include <limits>
#include "../math/abs.hpp"
#include "../math/neg.hpp"

namespace x4 {
	template<std::integral T>
	[[nodiscard]] constexpr T rvsn(T n, T radix = 10) noexcept {
		if (!radix) {
			return 0;
		} else if ((radix == 1) || (!std::unsigned_integral<T> && (radix == static_cast<T>(-1)))) {
			return n;
		}
		const bool neg = x4::neg(n);
		T result = 0;
		const auto next = [&n, radix, &result](T digit) -> void {
			n /= radix;
			if (x4::neg(digit)) {
				digit = x4::neg(radix) ? (digit - radix) : (digit + radix);
				++n;
			}
			result = result * radix + digit;
		};
		if (n == std::numeric_limits<T>::min()) {
			next(-(n % radix));
		}
		n = static_cast<T>(x4::abs(n));
		while (n) {
			next(n % radix);
		}
		return neg ? -result : result;
	}
}
