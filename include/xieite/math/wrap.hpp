#ifndef XIEITE_HEADER_MATH_WRAP
#	define XIEITE_HEADER_MATH_WRAP

#	include <cmath>
#	include <type_traits>
#	include "../concepts/Arithmetic.hpp"
#	include "../math/Result.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2, xieite::concepts::Arithmetic Arithmetic3>
	[[nodiscard]]
	constexpr std::common_type_t<Arithmetic1, Arithmetic2, Arithmetic3> wrap(const Arithmetic1 value, const Arithmetic2 maximum, const Arithmetic3 minimum = 0) noexcept {
		const std::common_type_t<Arithmetic2, Arithmetic3> difference = maximum - minimum + 1;
		return (std::fmod(std::fmod(value - minimum, difference) + difference, difference) + minimum);
	}
}

#endif
