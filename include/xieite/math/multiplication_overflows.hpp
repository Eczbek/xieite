#ifndef XIEITE_HEADER_MATH_MULTIPLICATION_OVERFLOWS
#	define XIEITE_HEADER_MATH_MULTIPLICATION_OVERFLOWS

#	include <limits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/absolute.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr bool multiplicationOverflows(const Arithmetic_ multiplier, const Arithmetic_ multiplicand) noexcept {
		return multiplier && multiplicand && ((xieite::math::absolute(((multiplier < 0) != (multiplicand < 0)) ? std::numeric_limits<Arithmetic_>::min() : std::numeric_limits<Arithmetic_>::max()) / xieite::math::absolute(multiplier)) < xieite::math::absolute(multiplicand));
	}
}

#endif
