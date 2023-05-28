#ifndef XIEITE_HEADER_MATH_DIGITS
#	define XIEITE_HEADER_MATH_DIGITS

#	include <cmath>
#	include <concepts>
#	include <type_traits>
#	include <xieite/math/logarithm.hpp>

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]]
	constexpr Integral digits(const Integral value, const Integral base = 10) noexcept {
		return std::ceil(xieite::math::logarithm(base, static_cast<std::make_unsigned_t<Integral>>(value) + 1 + !value));
	}
}

#endif
