#ifndef XIEITE_HEADER_MATH_IS_NEGATIVE
#	define XIEITE_HEADER_MATH_IS_NEGATIVE

#	include <concepts>
#	include "../concepts/specialization_of.hpp"

namespace xieite::math {
	template<std::unsigned_integral>
	struct BigInteger;

	template<std::unsigned_integral UnsignedIntegral_>
	[[nodiscard]] constexpr bool isNegative(const UnsignedIntegral_ value) noexcept {
		return false;
	}

	template<typename Number_>
	requires(std::signed_integral<Number_> || std::floating_point<Number_> || xieite::concepts::SpecializationOf<Number_, xieite::math::BigInteger>)
	[[nodiscard]] constexpr bool isNegative(const Number_ value) noexcept {
		return value < 0;
	}
}

#endif
