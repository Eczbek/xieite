#ifndef DETAIL_XTE_HEADER_MATH_LESS
#	define DETAIL_XTE_HEADER_MATH_LESS
#
#	include "../math/abs.hpp"
#	include "../math/highest.hpp"
#	include "../math/width.hpp"
#	include "../meta/end.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_number.hpp"
#	include "../trait/remove_cvref.hpp"
#	include <cmath>
#	include <concepts>
#	include <limits>
#	include <type_traits>
#	include <utility>

namespace xte {
	constexpr auto less =
		[]<typename T, typename U, xte::end...,
			bool are_numbers = xte::is_number<xte::remove_cvref<T>> && xte::is_number<xte::remove_cvref<U>>,
			typename common_type = [:std::common_with<T, U> ? ^^std::common_type_t<T, U> : ^^void:]>
		[[nodiscard]](T&& lhs, U&& rhs) static XTE_ARROW_FIRST(
			([](T lhs, U rhs) noexcept -> bool requires(are_numbers) {
				if constexpr (are_numbers) {
					bool is_neg = (lhs < 0);
					if (is_neg != (rhs < 0)) {
						return is_neg;
					}
					if constexpr ((xte::is_float<T> != xte::is_float<U>) && !std::numeric_limits<common_type>::has_infinity) {
						using uint_type = std::make_unsigned_t<typename[:xte::is_int<T> ? ^^T : ^^U:]>;
						if constexpr (([] {
							xte::uz exp = 0;
							for (auto max_float = std::numeric_limits<common_type>::max(); (max_float > 1) && (exp < xte::width<uint_type>); ++exp) {
								max_float /= 2;
							}
							return exp < xte::width<uint_type>;
						})()) {
							auto lhs_uint = static_cast<uint_type>(xte::abs(lhs));
							auto rhs_uint = static_cast<uint_type>(xte::abs(rhs));
							return (lhs_uint != rhs_uint)
								? (is_neg ? (lhs_uint > rhs_uint) : (lhs_uint < rhs_uint))
								: ((xte::is_int<T> ? 0 : std::fmod(lhs, 1)) < (xte::is_int<U> ? 0 : std::fmod(rhs, 1)));
						}
					}
					return static_cast<common_type>(lhs) < static_cast<common_type>(rhs);
				}
				std::unreachable();
			})(lhs, rhs),
			static_cast<bool>(XTE_FWD(lhs) < XTE_FWD(rhs)),
			static_cast<bool>(XTE_FWD(rhs) > XTE_FWD(lhs)),
			static_cast<bool>(static_cast<common_type>(XTE_FWD(lhs)) < static_cast<common_type>(XTE_FWD(rhs))),
			static_cast<bool>(static_cast<common_type>(XTE_FWD(rhs)) > static_cast<common_type>(XTE_FWD(lhs)))
		);
}

#endif
