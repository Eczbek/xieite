#ifndef XIEITE_HEADER__MATH__MULTIPLY
#	define XIEITE_HEADER__MATH__MULTIPLY

#	include <concepts>
#	include <limits>
#	include "../math/Product.hpp"

namespace xieite::math {
	template<std::unsigned_integral UnsignedInteger>
	constexpr xieite::math::Product<UnsignedInteger> multiply(const UnsignedInteger multiplier, const UnsignedInteger multiplicand) noexcept {
		constexpr UnsignedInteger halfSize = std::numeric_limits<UnsignedInteger>::digits / 2;
		constexpr UnsignedInteger halfBits = std::numeric_limits<UnsignedInteger>::max() >> halfSize;
		const UnsignedInteger foo = multiplier & halfBits;
		const UnsignedInteger bar = multiplier >> halfSize;
		const UnsignedInteger baz = multiplicand & halfBits;
		const UnsignedInteger qux = multiplicand >> halfSize;
		const UnsignedInteger byx = foo * baz;
		const UnsignedInteger hyk = foo * qux;
		const UnsignedInteger roq = bar * baz;
		return xieite::math::Product<UnsignedInteger>(byx + (hyk << halfSize) + (roq << halfSize), bar * qux + (hyk >> halfSize) + (roq >> halfSize) + (halfBits & (((byx >> halfSize) + (hyk & halfBits) + (roq & halfBits)) >> halfSize)));
	}
}

#endif
