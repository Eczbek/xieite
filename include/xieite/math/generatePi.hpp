#ifndef XIEITE_HEADER_MATH_GENERATEPI
#	define XIEITE_HEADER_MATH_GENERATEPI

#	include <concepts>
#	include <vector>
#	include <xieite/math/BigInteger.hpp>

namespace xieite::math {
	template<std::integral Integral = int>
	constexpr std::vector<Integral> generatePi(std::size_t digits) noexcept {
		xieite::math::BigInteger a = 180;
		xieite::math::BigInteger b = 1;
		xieite::math::BigInteger c = 60;
		xieite::math::BigInteger d = 2;
		std::vector<Integral> result;
		while (digits--) {
			const xieite::math::BigInteger e = (b * (d * 27 - 12) + a * 5) / c / 5;
			const xieite::math::BigInteger f = (d * 3 + 1) * (d * 3 + 2) * 3;
			a = (a + b * (d * 5 - 2) - c * e) * f * 10;
			b *= d * (d * 2 - 1) * 10;
			c *= f;
			++d;
			result.push_back(static_cast<Integral>(e));
		}
		return result;
	}
}

// This seems to use the Gauss-Legendre algorithm

#endif
