#ifndef XIEITE_HEADER_MATH_LOGARITHM
#	define XIEITE_HEADER_MATH_LOGARITHM

#	include <cmath>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Arithmetic Result = std::common_type_t<double, Arithmetic>>
	[[nodiscard]] constexpr Result logarithm(const Arithmetic base, const Arithmetic value) noexcept {
		return static_cast<Result>(std::log(value) / std::log(base));
		// `std::log` is slightly faster than `std::log2` and `std::log10` in my tests
	}
}

#endif
