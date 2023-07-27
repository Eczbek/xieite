#ifndef XIEITE_HEADER_MATH_DIGITS
#	define XIEITE_HEADER_MATH_DIGITS

#	include <cmath>
#	include <concepts>
#	include <cstddef>
#	include "../math/absolute.hpp"
#	include "../math/logarithm.hpp"

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]]
	constexpr std::size_t digits(const Integral value, const std::size_t base = 10) noexcept {
		return (!base ? 0 : ((base == 1) ? value : std::ceil(xieite::math::logarithm(base, xieite::math::absolute(value) + !value + 1))));
	}
}

#endif
