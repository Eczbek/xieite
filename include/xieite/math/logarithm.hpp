#ifndef XIEITE_HEADER_MATH_LOGARITHM
#	define XIEITE_HEADER_MATH_LOGARITHM

#	include <cmath>
#	include "../concepts/numeric.hpp"
#	include "../math/result.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2>
	[[nodiscard]] constexpr xieite::math::Result<Number1, Number2> logarithm(const Number1 base, const Number2 value) noexcept {
		return std::log(value) / std::log(base); // I found std::log to be slightly faster than std::log2 and std::log10
	}
}

#endif
