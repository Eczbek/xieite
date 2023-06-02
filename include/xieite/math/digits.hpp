#ifndef XIEITE_HEADER_MATH_DIGITS
#	define XIEITE_HEADER_MATH_DIGITS

#	include <cmath>
#	include <concepts>
#	include <cstddef>
#	include <xieite/math/logarithm.hpp>

namespace xieite::math {
	template<std::unsigned_integral UnsignedIntegral>
	[[nodiscard]]
	constexpr std::size_t digits(const UnsignedIntegral value, const std::size_t base = 10) noexcept {
		return std::ceil(xieite::math::logarithm(base, value + 1 + !value));
	}
}

#endif
