#ifndef DETAIL_XTE_HEADER_MATH_COMPARE
#	define DETAIL_XTE_HEADER_MATH_COMPARE
#
#	include "../math/abs.hpp"
#	include "../math/flip_order.hpp"
#	include "../math/is_inf.hpp"
#	include "../math/is_nan.hpp"
#	include "../math/rshift.hpp"
#	include "../meta/end.hpp"
#	include "../meta/wrap_type.hpp"
#	include "../preproc/returns.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_order.hpp"
#	include <cmath>
#	include <concepts>
#	include <compare>
#	include <type_traits>

namespace DETAIL_XTE::compare {
	template<typename lhs_type, typename rhs_type, xte::end...,
		typename common_type = [:std::common_with<lhs_type, rhs_type> ? ^^std::common_type<lhs_type, rhs_type> : ^^xte::wrap_type<void>:]::type>
	[[nodiscard]] constexpr auto less(const lhs_type& lhs, const rhs_type& rhs) XTE_RETURNS_FIRST(
		std::is_lt(lhs <=> rhs),
		std::is_gt(rhs <=> lhs),
		static_cast<bool>(lhs < rhs),
		static_cast<bool>(rhs > lhs),
		!static_cast<bool>(lhs >= rhs),
		!static_cast<bool>(rhs <= lhs),
		static_cast<bool>(static_cast<common_type>(lhs) < static_cast<common_type>(rhs)),
		static_cast<bool>(static_cast<common_type>(rhs) > static_cast<common_type>(lhs)),
		!static_cast<bool>(static_cast<common_type>(lhs) >= static_cast<common_type>(rhs)),
		!static_cast<bool>(static_cast<common_type>(rhs) <= static_cast<common_type>(lhs))
	)
}

namespace xte {
	template<typename lhs_type, typename rhs_type>
	[[nodiscard]] constexpr xte::is_order auto compare(const lhs_type& lhs, const rhs_type& rhs)
	noexcept(([] {
		if constexpr (xte::is_arithmetic<lhs_type> && xte::is_arithmetic<rhs_type>) {
			return true;
		} else if constexpr (requires { { lhs <=> rhs } -> xte::is_order; }) {
			return noexcept(lhs <=> rhs);
		} else if constexpr (requires { { rhs <=> lhs } -> xte::is_order; }) {
			return noexcept(rhs <=> lhs);
		} else if constexpr (requires { DETAIL_XTE::compare::less(lhs, rhs); DETAIL_XTE::compare::less(rhs, lhs); }) {
			return noexcept(DETAIL_XTE::compare::less(lhs, rhs)) && noexcept(DETAIL_XTE::compare::less(rhs, lhs));
		} else {
			return true;
		}
	})()) {
		if constexpr (xte::is_arithmetic<lhs_type> && xte::is_arithmetic<rhs_type>) {
			using order_type = [:(xte::is_float<lhs_type> || xte::is_float<rhs_type>) ? ^^std::partial_ordering : ^^std::strong_ordering:];
			if constexpr (xte::is_float<lhs_type> || xte::is_float<rhs_type>) {
				if (xte::is_nan(lhs) || xte::is_nan(rhs)) {
					return std::partial_ordering::unordered;
				}
			}
			order_type sign_order = (0 < lhs) <=> (0 < rhs);
			if (!std::is_eq(sign_order)) {
				return sign_order;
			}
			if (order_type inf_order = xte::is_inf(lhs) <=> xte::is_inf(rhs); !std::is_eq(inf_order)) {
				return (0 < lhs) ? inf_order : xte::flip_order(inf_order);
			}
			static constexpr auto compare_int_float = [](xte::is_int auto lhs, xte::is_float auto rhs) noexcept -> order_type {
				using unsigned_type = std::common_type_t<unsigned long long, std::make_unsigned_t<decltype(lhs)>>;
				using float_type = std::common_type_t<long double, decltype(rhs)>;
				static constexpr float_type chunk_size = std::pow(static_cast<float_type>(2), std::min(std::numeric_limits<unsigned_type>::digits, std::numeric_limits<float_type>::digits));
				order_type order = !std::fmod(rhs, 1) <=> true;
				auto lhs_abs = xte::abs(lhs);
				auto rhs_abs = static_cast<float_type>(xte::abs(rhs));
				while (lhs_abs && rhs_abs) {
					unsigned_type lhs_chunk = lhs_abs;
					if constexpr (std::numeric_limits<float_type>::digits < std::numeric_limits<unsigned_type>::digits) {
						lhs_chunk %= static_cast<unsigned_type>(1) << std::numeric_limits<float_type>::digits;
					}
					if (order_type chunk_order = lhs_chunk <=> static_cast<unsigned_type>(std::fmod(rhs_abs, chunk_size)); !std::is_eq(chunk_order)) {
						order = chunk_order;
					}
					lhs_abs = xte::rshift(lhs_abs, std::numeric_limits<float_type>::digits);
					rhs_abs = std::floor(rhs_abs / chunk_size);
				}
				if (order_type rest_order = !rhs_abs <=> !lhs_abs; !std::is_eq(rest_order)) {
					order = rest_order;
				}
				return (0 < lhs) ? order : xte::flip_order(order);
			};
			if constexpr (xte::is_int<lhs_type> && xte::is_float<rhs_type>) {
				return compare_int_float(lhs, rhs);
			} else if constexpr (xte::is_float<lhs_type> && xte::is_int<rhs_type>) {
				return xte::flip_order(compare_int_float(rhs, lhs));
			} else {
				using common_type = std::common_type_t<lhs_type, rhs_type>;
				return static_cast<common_type>(lhs) <=> static_cast<common_type>(rhs);
			}
		} else if constexpr (requires { { lhs <=> rhs } -> xte::is_order; }) {
			return lhs <=> rhs;
		} else if constexpr (requires { { rhs <=> lhs } -> xte::is_order; }) {
			return xte::flip_order(rhs <=> lhs);
		} else if constexpr (requires { DETAIL_XTE::compare::less(lhs, rhs); DETAIL_XTE::compare::less(rhs, lhs); }) {
			return DETAIL_XTE::compare::less(lhs, rhs)
				? std::weak_ordering::less
				: (DETAIL_XTE::compare::less(rhs, lhs)
					? std::weak_ordering::greater
					: std::weak_ordering::equivalent);
		} else {
			return std::partial_ordering::unordered;
		}
	};
}

#endif
