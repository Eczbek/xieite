#ifndef XIEITE_HEADER__MATH__COTANGENT
#	define XIEITE_HEADER__MATH__COTANGENT

#	include <cmath>
#	include "../concepts/Arithmetic.hpp"
#	include "../math/Result.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	constexpr xieite::math::Result<Arithmetic> cotangent(const Arithmetic value) noexcept {
		return (std::cos(value) / std::sin(value));
	}
}

#endif
