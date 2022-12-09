#pragma once
#include <concepts> // std::integral
#include <xieite/math/BigInt.hpp> // xieite::math::BigInt

namespace xieite::math {
	class PiGenerator {
	private:
		xieite::math::BigInt a;
		xieite::math::BigInt b;
		xieite::math::BigInt c;
		xieite::math::BigInt d;

	public:
		constexpr PiGenerator() noexcept
		: a(180), b(1), c(60), d(2) {}

		template<std::integral N = int>
		constexpr N next() noexcept {
			const xieite::math::BigInt e = (b * (d * 27 - 12) + a * 5) / c / 5;
			const xieite::math::BigInt f = (d * 3 + 1) * (d * 3 + 2) * 3;
			a = (a + b * (d * 5 - 2) - c * e) * f * 10;
			b *= d * (d * 2 - 1) * 10;
			c *= f;
			++d;
			return static_cast<N>(e);
		}
	};
}
