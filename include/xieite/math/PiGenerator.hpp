#pragma once
#include <concepts> // std::integral
#include <xieite/math/BigInteger.hpp>

namespace xieite::math {
	class PiGenerator {
	private:
		xieite::math::BigInteger a;
		xieite::math::BigInteger b;
		xieite::math::BigInteger c;
		xieite::math::BigInteger d;

	public:
		constexpr PiGenerator() noexcept
		: a(180), b(1), c(60), d(2) {}

		template<std::integral N = int>
		constexpr N next() noexcept {
			const xieite::math::BigInteger e = (b * (d * 27 - 12) + a * 5) / c / 5;
			const xieite::math::BigInteger f = (d * 3 + 1) * (d * 3 + 2) * 3;
			a = (a + b * (d * 5 - 2) - c * e) * f * 10;
			b *= d * (d * 2 - 1) * 10;
			c *= f;
			++d;
			return static_cast<N>(e);
		}
	};
}
