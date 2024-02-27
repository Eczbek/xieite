#ifndef XIEITE_HEADER_MATH_NEXT_POWER_OF_2
#	define XIEITE_HEADER_MATH_NEXT_POWER_OF_2

#	include <cmath>
#	include <concepts>
#	include <cstddef>

namespace xieite::math {
	template<std::unsigned_integral UnsignedInteger>
	[[nodiscard]] constexpr std::size_t nextPowerOf2(const UnsignedInteger value) noexcept {
		return static_cast<std::size_t>(std::ceil(std::log2(value)));
	}
}

#endif
