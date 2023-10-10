#pragma once

#include "../concepts/integer.hpp"

namespace xieite::math {
	template<xieite::concepts::Integer Integer>
	[[nodiscard]] constexpr bool isPrime(const Integer value) noexcept {
		if ((value < 2) || (value > 2) && !(value % 2)) {
			return false;
		}
		for (Integer i = 3; i * i <= value; i += 2) {
			if (!(value % i)) {
				return false;
			}
		}
		return true;
	}
}
