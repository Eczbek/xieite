#ifndef XIEITE_HEADER_MATH_CLOSEST_TO
#	define XIEITE_HEADER_MATH_CLOSEST_TO

#	include <concepts>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/difference.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic& closestTo(const Arithmetic target, Arithmetic& value1, Arithmetic& value2) noexcept {
		return (xieite::math::difference(target, value1) > xieite::math::difference(target, value2)) ? value2 : value1;
	}

	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic closestTo(const Arithmetic target, const Arithmetic& value1, const Arithmetic& value2) noexcept {
		Arithmetic copy1 = value1;
		Arithmetic copy2 = value2;
		return xieite::math::closestTo(target, copy1, copy2);
	}
}

#endif
