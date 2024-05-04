#ifndef XIEITE_HEADER_MATH_CEILING
#	define XIEITE_HEADER_MATH_CEILING

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_ceiling.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ ceiling(const Arithmetic_ value, const Arithmetic_ step = 1) noexcept {
		return xieite::math::divideCeiling(value, step) * step;
	}
}

#endif
