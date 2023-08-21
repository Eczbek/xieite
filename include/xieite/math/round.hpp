#ifndef XIEITE_HEADER__MATH__ROUND
#	define XIEITE_HEADER__MATH__ROUND

#	include <cmath>
#	include "../concepts/Arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2>
	constexpr Arithmetic1 round(const Arithmetic1 value, const Arithmetic2 step = 1) noexcept {
		return std::round(value / step) * step;
	}
}

#endif
