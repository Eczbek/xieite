#ifndef DETAIL_XIEITE_HEADER_MATH_DIV_MAGNIFY_HALF
#	define DETAIL_XIEITE_HEADER_MATH_DIV_MAGNIFY_HALF
#
#	include <cmath>
#	include <concepts>
#	include <type_traits>
#	include "../math/sign.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith div_magnify_half(Arith lhs, std::type_identity_t<Arith> rhs) noexcept {
		if constexpr (std::floating_point<Arith>) {
			const Arith result = lhs / rhs;
			return std::floor(result) + (result < 0) + (std::fmod(std::abs(result), 1) >= 0.5) * xieite::sign(result);
		} else {
			return static_cast<Arith>(lhs / rhs + ((lhs % rhs * xieite::sign(lhs)) >= (rhs / 2 * xieite::sign(rhs) + rhs % 2)) * xieite::sign(lhs, rhs));
		}
	}
}

#endif

// Thanks to Eisenwave (https://github.com/Eisenwave) for original integer division code
