#ifndef XIEITE_HEADER_MATH_IS_NEGATIVE
#	define XIEITE_HEADER_MATH_IS_NEGATIVE

#	include <concepts>
#	include "../concepts/specialization_of.hpp"

namespace xieite::math {
	template<std::unsigned_integral>
	struct BigInteger;

	template<std::unsigned_integral UnsignedInteger>
	[[nodiscard]] constexpr bool isNegative(const UnsignedInteger value) noexcept {
		return false;
	}

	template<typename Number>
	requires(std::signed_integral<Number> || std::floating_point<Number> || xieite::concepts::SpecializationOf<Number, xieite::math::BigInteger>)
	[[nodiscard]] constexpr bool isNegative(const Number value) noexcept {
		return value < 0;
	}
}

#endif
