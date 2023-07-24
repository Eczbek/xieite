#ifndef XIEITE_HEADER_MATH_COTANGENT
#	define XIEITE_HEADER_MATH_COTANGENT

#	include <cmath>
#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/math/Result.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]]
	constexpr xieite::math::Result<Arithmetic> cotangent(const Arithmetic value) noexcept {
		return std::cos(value) / std::sin(value);
	}
}

#endif
