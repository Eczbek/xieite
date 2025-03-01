#pragma once

#include <concepts>
#include <cstddef>
#include "../math/abs.hpp"
#include "../math/neg.hpp"

namespace x4 {
	template<std::integral T>
	[[nodiscard]] constexpr std::size_t digits(T n, T radix = 10) noexcept {
		if (!radix) {
			return 1;
		}
		if (radix == 1) {
			return static_cast<std::size_t>(x4::abs(n));
		}
		if (std::signed_integral<T> && (radix == static_cast<T>(-1))) {
			return static_cast<std::size_t>(x4::abs(n) * 2) + 1;
		}
		std::size_t result = 0;
		do {
			n = n / radix + x4::neg(n % radix);
			++result;
		} while (n);
		return result;
	}
}
