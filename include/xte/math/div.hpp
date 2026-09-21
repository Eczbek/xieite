#ifndef DETAIL_XTE_HEADER_MATH_DIV
#	define DETAIL_XTE_HEADER_MATH_DIV
#
#	include "../abs.hpp"
#	include "../arithmetic.hpp"
#	include "../make.hpp"
#	include "../math/float.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_float.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto div_floor(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>; xte::is_float<common_type>) {
			auto quot = xte::make<common_type>(dividend);
			return (..., (quot = xte::floor(quot / xte::make<common_type>(divisors))));
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			auto quot = static_cast<unsigned_type>(xte::abs(dividend));
			auto sign = static_cast<std::make_signed_t<common_type>>(xte::sign(dividend));
			(void)(..., (sign = xte::sign(sign, divisors), quot = quot / static_cast<unsigned_type>(xte::abs(divisors)) + static_cast<unsigned_type>(!!xte::rem(quot, divisors) * (sign < 0))));
			return static_cast<common_type>(quot * static_cast<unsigned_type>(sign));
		}
	}

	[[nodiscard]] constexpr auto div_ceil(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>; xte::is_float<common_type>) {
			auto quot = xte::make<common_type>(dividend);
			return (..., (quot = xte::ceil(quot / xte::make<common_type>(divisors))));
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			auto quot = static_cast<unsigned_type>(xte::abs(dividend));
			auto sign = static_cast<std::make_signed_t<common_type>>(xte::sign(dividend));
			(void)(..., (sign = xte::sign(sign, divisors), quot = quot / static_cast<unsigned_type>(xte::abs(divisors)) + static_cast<unsigned_type>(!!xte::rem(quot, divisors) * (sign > 0))));
			return static_cast<common_type>(quot * static_cast<unsigned_type>(sign));
		}
	}

	[[nodiscard]] constexpr auto div_trunc(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>; xte::is_float<common_type>) {
			auto quot = xte::make<common_type>(dividend);
			return (..., (quot = xte::floor(quot / xte::make<common_type>(divisors)) + (xte::sign(quot, divisors) < 0)));
		} else {
			return xte::div(dividend, divisors...);
		}
	}

	[[nodiscard]] constexpr auto div_magnify(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>; xte::is_float<common_type>) {
			auto quot = xte::make<common_type>(dividend);
			return (..., (quot = xte::ceil(quot / xte::make<common_type>(divisors)) - (xte::sign(quot, divisors) < 0)));
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			auto quot = static_cast<unsigned_type>(xte::abs(dividend));
			auto sign = static_cast<std::make_signed_t<common_type>>(xte::sign(dividend));
			(void)(..., (sign = xte::sign(sign, divisors), quot = quot / static_cast<unsigned_type>(xte::abs(divisors)) + static_cast<unsigned_type>(!!xte::rem(quot, divisors))));
			return static_cast<common_type>(quot * static_cast<unsigned_type>(sign));
		}
	}

	[[nodiscard]] constexpr auto div_floor_half(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>; xte::is_float<common_type>) {
			auto quot = xte::make<common_type>(dividend);
			common_type fraction = 0;
			return (..., (fraction = xte::rem(quot /= xte::make<common_type>(divisors), 1), quot = xte::floor(quot) + (quot < 0) + (fraction > 0.5) - (fraction <= -0.5)));
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			auto quot = static_cast<unsigned_type>(xte::abs(dividend));
			auto sign = static_cast<std::make_signed_t<common_type>>(xte::sign(dividend));
			(void)(..., (sign = xte::sign(sign, divisors), quot = quot / static_cast<unsigned_type>(xte::abs(divisors)) + (xte::rem(quot, divisors) >= (xte::abs(divisors) / 2 + ((divisors % 2) || (sign > 0))))));
			return static_cast<common_type>(quot * static_cast<unsigned_type>(sign));
		}
	}

	[[nodiscard]] constexpr auto div_ceil_half(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>; xte::is_float<common_type>) {
			auto quot = xte::make<common_type>(dividend);
			common_type fraction = 0;
			return (..., (fraction = xte::rem(quot /= xte::make<common_type>(divisors), 1), quot = xte::floor(quot) + (quot < 0) + (fraction >= 0.5) - (fraction < -0.5)));
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			auto quot = static_cast<unsigned_type>(xte::abs(dividend));
			auto sign = static_cast<std::make_signed_t<common_type>>(xte::sign(dividend));
			(void)(..., (sign = xte::sign(sign, divisors), quot = quot / static_cast<unsigned_type>(xte::abs(divisors)) + (xte::rem(quot, divisors) >= (xte::abs(divisors) / 2 + ((divisors % 2) || (sign < 0))))));
			return static_cast<common_type>(quot * static_cast<unsigned_type>(sign));
		}
	}

	[[nodiscard]] constexpr auto div_trunc_half(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>; xte::is_float<common_type>) {
			auto quot = xte::make<common_type>(dividend);
			common_type fraction = 0;
			return (..., (fraction = xte::rem(quot /= xte::make<common_type>(divisors), 1), quot = xte::floor(quot) + (quot < 0) + (fraction > 0.5) - (fraction < -0.5)));
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			auto quot = static_cast<unsigned_type>(xte::abs(dividend));
			auto sign = static_cast<std::make_signed_t<common_type>>(xte::sign(dividend));
			(void)(..., (sign = xte::sign(sign, divisors), quot = quot / static_cast<unsigned_type>(xte::abs(divisors)) + (xte::rem(quot, divisors) > (xte::abs(divisors) / 2))));
			return static_cast<common_type>(quot * static_cast<unsigned_type>(sign));
		}
	}

	[[nodiscard]] constexpr auto div_magnify_half(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>; xte::is_float<common_type>) {
			auto quot = xte::make<common_type>(dividend);
			common_type fraction = 0;
			return (..., (fraction = xte::rem(quot /= xte::make<common_type>(divisors), 1), quot = xte::floor(quot) + (quot < 0) + (fraction >= 0.5) - (fraction <= -0.5)));
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			auto quot = static_cast<unsigned_type>(xte::abs(dividend));
			auto sign = static_cast<std::make_signed_t<common_type>>(xte::sign(dividend));
			(void)(..., (sign = xte::sign(sign, divisors), quot = quot / static_cast<unsigned_type>(xte::abs(divisors)) + (xte::rem(quot, divisors) >= ((xte::abs(divisors) + 1) / 2))));
			return static_cast<common_type>(quot * static_cast<unsigned_type>(sign));
		}
	}
}

#endif
