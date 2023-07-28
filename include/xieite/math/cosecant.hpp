#ifndef XIEITE_HEADER_MATH_COSECANT
#	define XIEITE_HEADER_MATH_COSECANT

#	include <cmath>
#	include "../concepts/Arithmetic.hpp"
#	include "../math/Result.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]]
	constexpr xieite::math::Result<Arithmetic> cosecant(const Arithmetic value) noexcept {
		return (1 / std::sin(value));
	}
}

#endif
