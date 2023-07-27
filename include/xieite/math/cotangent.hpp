#ifndef XIEITE_HEADER_MATH_COTANGENT
#	define XIEITE_HEADER_MATH_COTANGENT

#	include <cmath>
#	include "../concepts/Arithmetic.hpp"
#	include "../math/Result.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]]
	constexpr xieite::math::Result<Arithmetic> cotangent(const Arithmetic value) noexcept {
		return (std::cos(value) / std::sin(value));
	}
}

#endif
