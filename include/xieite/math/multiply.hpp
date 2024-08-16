#ifndef XIEITE_HEADER_MATH_MULTIPLY
#	define XIEITE_HEADER_MATH_MULTIPLY

#	include <concepts>
#	include <limits>
#	include "../bits/size.hpp"
#	include "../math/product.hpp"

namespace xieite::math {
	template<std::unsigned_integral UnsignedIntegral>
	[[nodiscard]] constexpr xieite::math::Product<UnsignedIntegral> multiply(const UnsignedIntegral multiplier, const UnsignedIntegral multiplicand) noexcept {
		static constexpr UnsignedIntegral halfSize = xieite::bits::size<UnsignedIntegral> / 2;
		static constexpr UnsignedIntegral halfBits = std::numeric_limits<UnsignedIntegral>::max() >> halfSize;
		const UnsignedIntegral foo = multiplier & halfBits;
		const UnsignedIntegral bar = multiplier >> halfSize;
		const UnsignedIntegral baz = multiplicand & halfBits;
		const UnsignedIntegral qux = multiplicand >> halfSize;
		const UnsignedIntegral corge = foo * baz;
		const UnsignedIntegral grault = foo * qux;
		const UnsignedIntegral garply = bar * baz;
		return xieite::math::Product<UnsignedIntegral>(corge + (grault << halfSize) + (garply << halfSize), bar * qux + (grault >> halfSize) + (garply >> halfSize) + (halfBits & (((corge >> halfSize) + (grault & halfBits) + (garply & halfBits)) >> halfSize)));
	}
}

#endif
