#ifndef XIEITE_HEADER_MATH_CLOSESTTO
#	define XIEITE_HEADER_MATH_CLOSESTTO

#	include "../concepts/Arithmetic.hpp"
#	include "../math/Result.hpp"
#	include "../math/difference.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2, xieite::concepts::Arithmetic Arithmetic3>
	[[nodiscard]]
	constexpr xieite::math::Result<Arithmetic1, Arithmetic2, Arithmetic3>& closestTo(const Arithmetic1 target, Arithmetic2& value1, Arithmetic3& value2) noexcept {
		return ((value1 >= target) ? ((value2 >= target) ? ((value1 < value2) ? value1 : value2) : ((xieite::math::difference(target, value1) > xieite::math::difference(target, value2)) ? value1 : value2)) : ((value2 < target) ? ((value1 > value2) ? value1 : value2) : ((xieite::math::difference(target, value1) < xieite::math::difference(target, value2)) ? value1 : value2)));
	}

	template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2, xieite::concepts::Arithmetic Arithmetic3>
	[[nodiscard]]
	constexpr const xieite::math::Result<Arithmetic1, Arithmetic2, Arithmetic3>& closestTo(const Arithmetic1 target, const Arithmetic2& value1, const Arithmetic3& value2) noexcept {
		return ((value1 >= target) ? ((value2 >= target) ? ((value1 < value2) ? value1 : value2) : ((xieite::math::difference(target, value1) > xieite::math::difference(target, value2)) ? value1 : value2)) : ((value2 < target) ? ((value1 > value2) ? value1 : value2) : ((xieite::math::difference(target, value1) < xieite::math::difference(target, value2)) ? value1 : value2)));
	}
}

#endif
