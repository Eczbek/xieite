#ifndef XIEITE_HEADER_MATH_LOGARITHM
#	define XIEITE_HEADER_MATH_LOGARITHM

#	include <cmath>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr std::common_type_t<double, Number> logarithm(const Number base, const Number value) noexcept {
		return std::log(value) / std::log(base); // std::log is slightly faster than std::log2 and std::log10 in my tests
	}
}

#endif
