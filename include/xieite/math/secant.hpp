#ifndef XIEITE_HEADER_MATH_SECANT
#	define XIEITE_HEADER_MATH_SECANT

#	include <cmath>
#	include "../concepts/Arithmetic.hpp"
#	include "../math/Result.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]]
	constexpr xieite::math::Result<Arithmetic> secant(const Arithmetic value) noexcept {
		return (1 / std::cos(value));
	}
}

#endif
