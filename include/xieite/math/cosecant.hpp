#ifndef XIEITE_HEADER__MATH__COSECANT
#	define XIEITE_HEADER__MATH__COSECANT

#	include <cmath>
#	include "../concepts/Arithmetic.hpp"
#	include "../math/Result.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	constexpr xieite::math::Result<Arithmetic> cosecant(const Arithmetic value) noexcept {
		return 1 / std::sin(value);
	}
}

#endif
