#ifndef XIEITE_HEADER__MATH__ALMOST_EQUAL
#	define XIEITE_HEADER__MATH__ALMOST_EQUAL

#	include "../concepts/Arithmetic.hpp"
#	include "../math/absolute.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2>
	constexpr bool almostEqual(const Arithmetic1 value1, const Arithmetic2 value2) noexcept {
		return xieite::math::absolute(value1 - value2) < 1; // TODO: ?
	}
}

#endif
