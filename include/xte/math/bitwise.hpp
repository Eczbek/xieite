#ifndef DETAIL_XTE_HEADER_MATH_BITWISE
#	define DETAIL_XTE_HEADER_MATH_BITWISE
#
#	include "../abs.hpp"
#	include "../aliases.hpp"
#	include "../limits.hpp"
#	include "../math/sign_cast.hpp"
#	include "../trait/is_int.hpp"

namespace xte {
	template<xte::is_int value_type, xte::is_int count_type = xte::uz>
	[[nodiscard]] constexpr value_type rshift(value_type value, count_type count = 1) noexcept {
		if (xte::abs(count) >= xte::width<value_type>) {
			return 0;
		}
		return static_cast<value_type>((count < 0) ? (xte::as_unsigned(value) << -count) : (xte::as_unsigned(value) >> count));
	}

	template<xte::is_int value_type, xte::is_int count_type = xte::uz>
	[[nodiscard]] constexpr value_type lshift(value_type value, count_type count = 1) noexcept {
		if (xte::abs(count) >= xte::width<value_type>) {
			return 0;
		}
		return static_cast<value_type>((count < 0) ? (xte::as_unsigned(value) >> -count) : (xte::as_unsigned(value) << count));
	}

	[[nodiscard]] constexpr bool is_single_bit(xte::is_int auto value) noexcept {
		return value && !(xte::as_unsigned(value) & ~-xte::as_unsigned(value));
	}
	
	[[nodiscard]] constexpr xte::uz leading_zeros(xte::is_int auto value) noexcept {
		xte::uz count = 0;
		for (; value; value = xte::rshift(value)) {
			++count;
		}
		return xte::width<decltype(value)> - count;
	}

	[[nodiscard]] constexpr xte::uz trailing_zeros(xte::is_int auto value) noexcept {
		xte::uz count = 0;
		while (!(value & 1) && (++count < xte::width<decltype(value)>)) {
			value = xte::rshift(value);
		}
		return count;
	}

	template<xte::is_int value_type>
	[[nodiscard]] constexpr value_type bit_floor(value_type value) noexcept {
		return xte::lshift(static_cast<value_type>(1), xte::width<value_type> - xte::leading_zeros(value) - 1);
	}

	template<xte::is_int value_type>
	[[nodiscard]] constexpr value_type bit_ceil(value_type value) noexcept {
		if (xte::is_single_bit(value |= !value)) {
			return value;
		}
		return xte::lshift(static_cast<value_type>(1), xte::width<value_type> - xte::leading_zeros(value));
	}

	[[nodiscard]] constexpr bool bit_at(xte::is_int auto value, xte::uz pos) noexcept {
		return xte::rshift(value, pos) & 1;
	}
}

#endif
