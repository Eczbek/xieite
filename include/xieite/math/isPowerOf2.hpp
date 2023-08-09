#ifndef XIEITE_HEADER__MATH__IS_POWER_OF_2
#	define XIEITE_HEADER__MATH__IS_POWER_OF_2

#	include <concepts>

namespace xieite::math {
	template<std::unsigned_integral UnsignedInteger>
	constexpr bool isPowerOf2(const UnsignedInteger value) noexcept {
		return (value && !(value & (value - 1)));
	}
}

#endif
