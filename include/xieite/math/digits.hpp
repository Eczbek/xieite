#ifndef XIEITE_HEADER_MATH_DIGITS
#	define XIEITE_HEADER_MATH_DIGITS

#	include <cmath>
#	include <concepts>
#	include <cstddef>
#	include <xieite/math/absolute.hpp>
#	include <xieite/math/logarithm.hpp>

namespace xieite::math {
	[[nodiscard]]
	constexpr std::size_t digits(const std::integral auto value, const std::size_t base = 10) noexcept {
		return std::ceil(xieite::math::logarithm(base, xieite::math::absolute(value) + !value + 1));
	}
}

#endif
