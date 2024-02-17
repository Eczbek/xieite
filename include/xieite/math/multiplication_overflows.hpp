#ifndef XIEITE_HEADER_MATH_MULTIPLICATION_OVERFLOWS
#	define XIEITE_HEADER_MATH_MULTIPLICATION_OVERFLOWS

#	include <limits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/absolute.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr bool multiplicationOverflows(const Number multiplier, const Number multiplicand) noexcept {
		return multiplier && multiplicand && ((xieite::math::absolute(((multiplier < 0) != (multiplicand < 0)) ? std::numeric_limits<Number>::min() : std::numeric_limits<Number>::max()) / xieite::math::absolute(multiplier)) < xieite::math::absolute(multiplicand));
	}
}

#endif
