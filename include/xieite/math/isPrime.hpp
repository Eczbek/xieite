#pragma once
#include <concepts> // std::integral

namespace xieite::math {
	template<std::integral N>
	[[nodiscard]]
	constexpr bool isPrime(const N value) noexcept {
		for (N i = 0; i * i <= value; ++i)
			if (value % i == 0)
				return false;
		return value > 0;
	}
}
