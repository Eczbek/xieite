#pragma once

#include <concepts>

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]]
	constexpr bool isPrime(const Integral value) noexcept {
		for (Integral i = 0; i * i <= value; ++i)
			if (value % i == 0)
				return false;
		return value > 0;
	}
}
