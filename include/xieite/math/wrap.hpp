#ifndef XIEITE_HEADER_MATH_WRAP
#	define XIEITE_HEADER_MATH_WRAP

#	include <cmath>
#	include <type_traits>
#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/math/Result.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2, xieite::concepts::Arithmetic Number3>
	[[nodiscard]]
	constexpr std::common_type_t<Number1, Number2, Number3> wrap(const Number1 value, const Number2 maximum, const Number3 minimum = 0.0) noexcept {
		const std::common_type_t<Number2, Number3> difference = maximum - minimum + 1.0;
		return std::fmod(std::fmod(value - minimum, difference) + difference, difference) + minimum;
	}
}

#endif
