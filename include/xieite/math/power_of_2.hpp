#ifndef XIEITE_HEADER_MATH_POWER_OF_2
#	define XIEITE_HEADER_MATH_POWER_OF_2

#	include <concepts>

namespace xieite::math {
	template<std::unsigned_integral UnsignedInteger>
	[[nodiscard]] constexpr bool powerOf2(const UnsignedInteger value) noexcept {
		return value && !(value & (value - 1));
	}
}

#endif
