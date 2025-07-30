#ifndef DETAIL_XIEITE_HEADER_MATH_DIV_FLOOR_HALF
#	define DETAIL_XIEITE_HEADER_MATH_DIV_FLOOR_HALF
#
#	include <cmath>
#	include <concepts>
#	include <type_traits>
#	include "../math/sign.hpp"
#	include "../math/ssize_t.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith div_floor_half(Arith lhs, std::type_identity_t<Arith> rhs) noexcept {
		if constexpr (std::floating_point<Arith>) {
			const Arith result = lhs / rhs;
			const Arith fractional = std::fmod(result, 1);
			return std::floor(result) + (result < 0) + (fractional > 0.5) - (fractional <= -0.5);
		} else {
			const xieite::ssize_t quot_sign = xieite::sign(lhs, rhs);
			return static_cast<Arith>(lhs / rhs + ((lhs % rhs * xieite::sign(lhs)) >= (rhs / 2 * xieite::sign(rhs) + ((rhs % 2) || (quot_sign >= 0)))) * quot_sign);
		}
	}
}

#endif

// Thanks to Eisenwave (https://github.com/Eisenwave) for original integer division code
