#ifndef XIEITE_HEADER_MATH_LOGARITHM
#	define XIEITE_HEADER_MATH_LOGARITHM

#	include <cmath>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr std::common_type_t<double, Arithmetic_> logarithm(const Arithmetic_ base, const Arithmetic_ value) noexcept {
		return std::log(value) / std::log(base);
		// `std::log` is slightly faster than `std::log2` and `std::log10` in my tests
	}
}

#endif
