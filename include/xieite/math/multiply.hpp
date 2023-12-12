#ifndef XIEITE_HEADER_MATH_MULTIPLY
#	define XIEITE_HEADER_MATH_MULTIPLY

#	include <concepts>
#	include <limits>
#	include "../math/product.hpp"

namespace xieite::math {
	template<std::unsigned_integral UnsignedInteger>
	[[nodiscard]] constexpr xieite::math::Product<UnsignedInteger> multiply(const UnsignedInteger multiplier, const UnsignedInteger multiplicand) noexcept {
		static constexpr UnsignedInteger halfSize = std::numeric_limits<UnsignedInteger>::digits / 2;
		static constexpr UnsignedInteger halfBits = std::numeric_limits<UnsignedInteger>::max() >> halfSize;
		const UnsignedInteger foo = multiplier & halfBits;
		const UnsignedInteger bar = multiplier >> halfSize;
		const UnsignedInteger baz = multiplicand & halfBits;
		const UnsignedInteger qux = multiplicand >> halfSize;
		const UnsignedInteger corge = foo * baz;
		const UnsignedInteger grault = foo * qux;
		const UnsignedInteger garply = bar * baz;
		return xieite::math::Product<UnsignedInteger>(corge + (grault << halfSize) + (garply << halfSize), bar * qux + (grault >> halfSize) + (garply >> halfSize) + (halfBits & (((corge >> halfSize) + (grault & halfBits) + (garply & halfBits)) >> halfSize)));
	}
}

#endif
