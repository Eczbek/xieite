#ifndef XIEITE_HEADER_MATH_ADDITION_OVERFLOWS
#	define XIEITE_HEADER_MATH_ADDITION_OVERFLOWS

#	include <limits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/is_negative.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool additionOverflows(const Arithmetic augend, const Arithmetic addend) noexcept {
		return augend && addend && (xieite::math::isNegative(augend) ? ((std::numeric_limits<Arithmetic>::min() - augend) > addend) : ((std::numeric_limits<Arithmetic>::max() - augend) < addend));
	}
}

#endif
