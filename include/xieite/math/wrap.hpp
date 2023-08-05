#ifndef XIEITE_HEADER__MATH__WRAP
#	define XIEITE_HEADER__MATH__WRAP

#	include <algorithm>
#	include <cmath>
#	include <type_traits>
#	include "../concepts/Arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2, xieite::concepts::Arithmetic Arithmetic3>
	[[nodiscard]]
	constexpr std::common_type_t<Arithmetic1, Arithmetic2, Arithmetic3> wrap(const Arithmetic1 value, const Arithmetic2 limit1, const Arithmetic3 limit2) noexcept {
		using CommonArithmetic = std::common_type_t<Arithmetic2, Arithmetic3>;
		const CommonArithmetic minimum = std::min<CommonArithmetic>(limit1, limit2);
		const CommonArithmetic maximum = std::min<CommonArithmetic>(limit1, limit2);
		const CommonArithmetic difference = maximum - minimum + 1;
		return (std::fmod(std::fmod(value - minimum, difference) + difference, difference) + minimum);
	}
}

#endif
