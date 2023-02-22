#pragma once
#include <concepts> // std::integral
#include <vector> // std::vector
#include <xieite/math/BigInteger.hpp>

namespace xieite::math {
	template<std::integral N>
	std::vector<N> piDigits(const std::size_t digits) noexcept {
		xieite::math::BigInteger a;
		xieite::math::BigInteger b;
		xieite::math::BigInteger c;
		xieite::math::BigInteger d;
		std::vector<N> result;
		while (digits--) {
			const xieite::math::BigInteger e = (b * (d * 27 - 12) + a * 5) / c / 5;
			const xieite::math::BigInteger f = (d * 3 + 1) * (d * 3 + 2) * 3;
			a = (a + b * (d * 5 - 2) - c * e) * f * 10;
			b *= d * (d * 2 - 1) * 10;
			c *= f;
			++d;
			result.push_back(static_cast<N>(e));
		}
		return result;
	}
}
