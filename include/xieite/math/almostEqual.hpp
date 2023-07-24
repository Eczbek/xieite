#ifndef XIEITE_HEADER_MATH_ALMOSTEQUAL
#	define XIEITE_HEADER_MATH_ALMOSTEQUAL

#	include <limits>
#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/math/Result.hpp>
#	include <xieite/math/absolute.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2>
	[[nodiscard]]
	constexpr bool almostEqual(const Arithmetic1 value1, const Arithmetic2 value2) noexcept {
		return (xieite::math::absolute(value1 - value2) <= std::numeric_limits<xieite::math::Result<Arithmetic1, Arithmetic2>>::epsilon());
	}
}

#endif
