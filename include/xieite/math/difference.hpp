#ifndef XIEITE_HEADER_MATH_DIFFERENCE
#	define XIEITE_HEADER_MATH_DIFFERENCE

#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../types/try_unsigned.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr xieite::types::TryUnsigned<Number> difference(const Number value1, const Number value2) noexcept {
		return (value1 > value2) ? (static_cast<xieite::types::TryUnsigned<Number>>(value1) - static_cast<xieite::types::TryUnsigned<Number>>(value2)) : (static_cast<xieite::types::TryUnsigned<Number>>(value2) - static_cast<xieite::types::TryUnsigned<Number>>(value1));
	}
}

#endif
