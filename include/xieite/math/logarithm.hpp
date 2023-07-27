#ifndef XIEITE_HEADER_MATH_LOGARITHM
#	define XIEITE_HEADER_MATH_LOGARITHM

#	include <cmath>
#	include "../concepts/Arithmetic.hpp"
#	include "../math/Result.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2>
	[[nodiscard]]
	constexpr xieite::math::Result<Arithmetic1, Arithmetic2> logarithm(const Arithmetic1 base, const Arithmetic2 value) noexcept {
		return (std::log(value) / std::log(base));
	}
}

#endif
