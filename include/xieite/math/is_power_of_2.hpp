#ifndef XIEITE_HEADER_MATH_IS_POWER_OF_2
#	define XIEITE_HEADER_MATH_IS_POWER_OF_2

#	include <concepts>

namespace xieite::math {
	template<std::unsigned_integral UnsignedIntegral_>
	[[nodiscard]] constexpr bool isPowerOf2(const UnsignedIntegral_ value) noexcept {
		return value && !(value & (value - 1));
	}
}

#endif
