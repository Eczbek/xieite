#ifndef XIEITE_HEADER__MATH__GENERATE_PI
#	define XIEITE_HEADER__MATH__GENERATE_PI

#	include <concepts>
#	include <vector>
#	include "../math/BigInteger.hpp"

namespace xieite::math {
	template<std::integral Integer = int>
	[[nodiscard]]
	constexpr std::vector<Integer> generatePi(std::size_t digits) noexcept {
		xieite::math::BigInteger a = 180;
		xieite::math::BigInteger b = 1;
		xieite::math::BigInteger c = 60;
		xieite::math::BigInteger d = 2;
		std::vector<Integer> result;
		while (digits--) {
			const xieite::math::BigInteger e = (b * (d * 27 - 12) + a * 5) / c / 5;
			const xieite::math::BigInteger f = (d * 3 + 1) * (d * 3 + 2) * 3;
			a = (a + b * (d * 5 - 2) - c * e) * f * 10;
			b *= d * (d * 2 - 1) * 10;
			c *= f;
			++d;
			result.push_back(static_cast<Integer>(e));
		}
		return result;
	}
}

// This seems to use the Gauss-Legendre algorithm

#endif
