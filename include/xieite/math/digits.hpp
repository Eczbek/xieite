#ifndef XIEITE_HEADER_MATH_DIGITS
#	define XIEITE_HEADER_MATH_DIGITS

#	include <cmath>
#	include <cstddef>
#	include "../concepts/arithmetic.hpp"
#	include "../math/absolute.hpp"
#	include "../math/logarithm.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr std::size_t digits(const Number value, const std::size_t base = 10) noexcept {
		return !base ? 0 : ((base == 1) ? value : static_cast<std::size_t>(std::floor(xieite::math::logarithm(base, xieite::math::absolute(value) + !value)) + 1));
	}
}

#endif
