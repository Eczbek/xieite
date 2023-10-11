#ifndef XIEITE_HEADER_MATH_WRAP
#	define XIEITE_HEADER_MATH_WRAP

#	include <algorithm>
#	include <type_traits>
#	include "../concepts/numeric.hpp"
#	include "../math/modulo.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr Number wrap(const Number value, const Number limit1, const Number limit2) noexcept {
		const Number minimum = std::min(limit1, limit2);
		return xieite::math::modulo(value - minimum, std::max(limit1, limit2) - minimum + 1) + minimum;
	}
}

#endif
