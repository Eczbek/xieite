#ifndef XIEITE_HEADER_MATH_ADDITION_OVERFLOWS
#	define XIEITE_HEADER_MATH_ADDITION_OVERFLOWS

#	include <limits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr bool additionOverflows(const Number augend, const Number addend) noexcept {
		return augend && addend && ((augend >= 0) ? ((std::numeric_limits<Number>::max() - augend) < addend) : ((std::numeric_limits<Number>::min() - augend) > addend));
	}
}

#endif
