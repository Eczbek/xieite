#ifndef DETAIL_XTE_HEADER_MATH_FLOAT
#	define DETAIL_XTE_HEADER_MATH_FLOAT
#
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_float.hpp"
#	include <cmath>

namespace xte {
	[[nodiscard]] constexpr bool is_finite(xte::is_arithmetic auto value) noexcept {
		if constexpr (xte::is_float<decltype(value)>) {
			return std::isfinite(value);
		} else {
			return true;
		}
	}

	[[nodiscard]] constexpr bool is_infinite(xte::is_arithmetic auto value) noexcept {
		if constexpr (xte::is_float<decltype(value)>) {
			return std::isinf(value);
		} else {
			return false;
		}
	}

	[[nodiscard]] constexpr bool is_nan(xte::is_arithmetic auto value) noexcept {
		return value != value;
	}

	[[nodiscard]] constexpr bool is_neg(xte::is_arithmetic auto value) noexcept {
		if constexpr (xte::is_float<decltype(value)>) {
			return std::signbit(value);
		} else {
			return value < 0;
		}
	}

	template<xte::is_arithmetic value_type>
	[[nodiscard]] constexpr value_type floor(value_type value) noexcept {
		if constexpr (xte::is_float<decltype(value)>) {
			return std::floor(value);
		} else {
			return value;
		}
	}

	template<xte::is_arithmetic value_type>
	[[nodiscard]] constexpr value_type ceil(value_type value) noexcept {
		if constexpr (xte::is_float<decltype(value)>) {
			return std::ceil(value);
		} else {
			return value;
		}
	}
}

#endif
