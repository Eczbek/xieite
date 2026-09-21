#ifndef DETAIL_XTE_HEADER_APPROX_EQUAL
#	define DETAIL_XTE_HEADER_APPROX_EQUAL
#
#	include "./abs.hpp"
#	include "./compare.hpp"
#	include "./math/diff.hpp"
#	include "./math/float.hpp"
#	include "./trait/is_arithmetic.hpp"
#	include "./trait/is_float.hpp"
#	include <limits>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr bool approx_equal(xte::is_arithmetic auto lhs, xte::is_arithmetic auto rhs) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(lhs), decltype(rhs)>; xte::is_float<common_type>) {
			auto diff = xte::diff(lhs, rhs);
			return diff <= (std::numeric_limits<common_type>::epsilon() * (((0 < diff) && (diff < 1)) ? (1 / diff) : diff));
		} else {
			return xte::equal(lhs, rhs);
		}
	}

	[[nodiscard]] constexpr bool approx_equal(xte::is_arithmetic auto lhs, xte::is_arithmetic auto rhs, xte::is_arithmetic auto epsilon) noexcept {
		return xte::diff(lhs, rhs) <= xte::abs(epsilon);
	}

	[[nodiscard]] constexpr bool approx_less_equal(xte::is_arithmetic auto lhs, xte::is_arithmetic auto rhs) noexcept {
		return xte::approx_equal(lhs, rhs) || xte::less_equal(lhs, rhs);
	}

	[[nodiscard]] constexpr bool approx_less_equal(xte::is_arithmetic auto lhs, xte::is_arithmetic auto rhs, xte::is_arithmetic auto epsilon) noexcept {
		return xte::approx_equal(lhs, rhs, epsilon) || xte::less_equal(lhs, rhs);
	}

	[[nodiscard]] constexpr bool approx_greater_equal(xte::is_arithmetic auto lhs, xte::is_arithmetic auto rhs) noexcept {
		return xte::approx_equal(lhs, rhs) || xte::greater_equal(lhs, rhs);
	}

	[[nodiscard]] constexpr bool approx_greater_equal(xte::is_arithmetic auto lhs, xte::is_arithmetic auto rhs, xte::is_arithmetic auto epsilon) noexcept {
		return xte::approx_equal(lhs, rhs, epsilon) || xte::greater_equal(lhs, rhs);
	}

	[[nodiscard]] constexpr bool approx_equal_slope(xte::is_arithmetic auto lhs, xte::is_arithmetic auto rhs) noexcept {
		return (xte::is_infinite(lhs) && xte::is_infinite(rhs)) || xte::approx_equal(lhs, rhs);
	}

	[[nodiscard]] constexpr bool approx_equal_slope(xte::is_arithmetic auto lhs, xte::is_arithmetic auto rhs, xte::is_arithmetic auto epsilon) noexcept {
		return (xte::is_infinite(lhs) && xte::is_infinite(rhs)) || xte::approx_equal(lhs, rhs, epsilon);
	}
}

#endif
