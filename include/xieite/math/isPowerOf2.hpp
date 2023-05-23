#ifndef XIEITE_HEADER_MATH_ISPOWEROF2
#	define XIEITE_HEADER_MATH_ISPOWEROF2

#	include <concepts>

namespace xieite::math {
	[[nodiscard]]
	constexpr bool isPowerOf2(const std::unsigned_integral auto value) noexcept {
		return value && !(value & (value - 1));
	}
}

#endif
