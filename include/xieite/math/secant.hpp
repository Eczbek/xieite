#ifndef XIEITE_HEADER_MATH_SECANT
#	define XIEITE_HEADER_MATH_SECANT

#	include <cmath>
#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/math/Result.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]]
	constexpr xieite::math::Result<Arithmetic> secant(const Arithmetic value) noexcept {
		return 1.0 / std::cos(value);
	}
}

#endif
