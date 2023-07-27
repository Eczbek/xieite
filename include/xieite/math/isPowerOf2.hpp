#ifndef XIEITE_HEADER_MATH_ISPOWEROF2
#	define XIEITE_HEADER_MATH_ISPOWEROF2

#	include <concepts>

namespace xieite::math {
	template<std::unsigned_integral UnsignedIntegral>
	[[nodiscard]]
	constexpr bool isPowerOf2(const UnsignedIntegral value) noexcept {
		return (value && !(value & (value - 1)));
	}
}

#endif
