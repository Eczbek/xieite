#ifndef XIEITE_HEADER_MATH_DIFFERENCE
#	define XIEITE_HEADER_MATH_DIFFERENCE

#	include <type_traits>
#	include "../concepts/numeric.hpp"
#	include "../types/maybe_unsigned.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr xieite::types::MaybeUnsigned<Number> difference(const Number value1, const Number value2) noexcept {
		return (value1 > value2) ? (static_cast<xieite::types::MaybeUnsigned<Number>>(value1) - static_cast<xieite::types::MaybeUnsigned<Number>>(value2)) : (static_cast<xieite::types::MaybeUnsigned<Number>>(value2) - static_cast<xieite::types::MaybeUnsigned<Number>>(value1));
	}
}

#endif
