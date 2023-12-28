#ifndef XIEITE_HEADER_MATH_ALMOST_EQUAL
#	define XIEITE_HEADER_MATH_ALMOST_EQUAL

#	include <limits>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/absolute.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2>
	[[nodiscard]] constexpr bool almostEqual(const Number1 value1, const Number2 value2) noexcept {
		return xieite::math::absolute(value1 - value2) <= std::numeric_limits<std::common_type_t<Number1, Number2>>::epsilon();
	}
}

#endif
