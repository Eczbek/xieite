#ifndef XIEITE_HEADER__MATH__WRAP
#	define XIEITE_HEADER__MATH__WRAP

#	include <algorithm>
#	include <type_traits>
#	include "../concepts/Numeric.hpp"
#	include "../math/modulo.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	constexpr Number wrap(const Number value, const Number limit1, const Number limit2) noexcept {
		const Number minimum = std::min(limit1, limit2);
		return xieite::math::modulo(value - minimum, std::max(limit1, limit2) - minimum + 1) + minimum;
	}
}

#endif
