#ifndef XIEITE_HEADER__MATH__WRAP
#	define XIEITE_HEADER__MATH__WRAP

#	include <algorithm>
#	include <cmath>
#	include <type_traits>
#	include "../concepts/Numeric.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2, xieite::concepts::Numeric Number3>
	constexpr std::common_type_t<Number1, Number2, Number3> wrap(const Number1 value, const Number2 limit1, const Number3 limit2) noexcept {
		using CommonNumber = std::common_type_t<Number2, Number3>;
		const CommonNumber minimum = std::min<CommonNumber>(limit1, limit2);
		const CommonNumber maximum = std::min<CommonNumber>(limit1, limit2);
		const CommonNumber difference = maximum - minimum + 1;
		return std::fmod(std::fmod(value - minimum, difference) + difference, difference) + minimum;
	}
}

#endif
