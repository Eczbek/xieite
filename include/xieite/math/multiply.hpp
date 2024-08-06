#ifndef XIEITE_HEADER_MATH_MULTIPLY
#	define XIEITE_HEADER_MATH_MULTIPLY

#	include <concepts>
#	include <limits>
#	include "../bits/size.hpp"
#	include "../math/product.hpp"

namespace xieite::math {
	template<std::unsigned_integral UnsignedIntegral_>
	[[nodiscard]] constexpr xieite::math::Product<UnsignedIntegral_> multiply(const UnsignedIntegral_ multiplier, const UnsignedIntegral_ multiplicand) noexcept {
		static constexpr UnsignedIntegral_ halfSize = xieite::bits::size<UnsignedIntegral_> / 2;
		static constexpr UnsignedIntegral_ halfBits = std::numeric_limits<UnsignedIntegral_>::max() >> halfSize;
		const UnsignedIntegral_ foo = multiplier & halfBits;
		const UnsignedIntegral_ bar = multiplier >> halfSize;
		const UnsignedIntegral_ baz = multiplicand & halfBits;
		const UnsignedIntegral_ qux = multiplicand >> halfSize;
		const UnsignedIntegral_ corge = foo * baz;
		const UnsignedIntegral_ grault = foo * qux;
		const UnsignedIntegral_ garply = bar * baz;
		return xieite::math::Product<UnsignedIntegral_>(corge + (grault << halfSize) + (garply << halfSize), bar * qux + (grault >> halfSize) + (garply >> halfSize) + (halfBits & (((corge >> halfSize) + (grault & halfBits) + (garply & halfBits)) >> halfSize)));
	}
}

#endif
