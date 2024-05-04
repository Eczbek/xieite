#ifndef XIEITE_HEADER_MATH_CLOSEST_TO
#	define XIEITE_HEADER_MATH_CLOSEST_TO

#	include <concepts>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/difference.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_& closestTo(const Arithmetic_ target, Arithmetic_& value1, Arithmetic_& value2) noexcept {
		return (xieite::math::difference(target, value1) > xieite::math::difference(target, value2)) ? value2 : value1;
	}

	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ closestTo(const Arithmetic_ target, const Arithmetic_& value1, const Arithmetic_& value2) noexcept {
		Arithmetic_ copy1 = value1;
		Arithmetic_ copy2 = value2;
		return xieite::math::closestTo(target, copy1, copy2);
	}
}

#endif
