#pragma once

#include <cmath>
#include <concepts>


namespace gcufl::math {
	template <std::integral N>
	constexpr bool isPrime(const N value) noexcept {
		for (N i = 0; i <= std::sqrt(value); ++i)
			if (value % i == 0)
				return false;
		return value > 0;
	}
}
