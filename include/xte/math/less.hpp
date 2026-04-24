#ifndef DETAIL_XTE_HEADER_MATH_LESS
#	define DETAIL_XTE_HEADER_MATH_LESS
#
#	include "../meta/end.hpp"
#	include "../meta/fake.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/is_noex.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_signed.hpp"
#	include "../trait/is_unsigned.hpp"
#	include <concepts>
#	include <type_traits>

namespace xte {
	constexpr auto less = []<typename T, typename U, xte::end...,
		bool are_ints = xte::is_int<T> && xte::is_int<U>,
		bool has_lt = (requires { xte::fake<T>() < xte::fake<U>(); }),
		bool has_gt = (requires { xte::fake<U>() > xte::fake<T>(); }),
		typename common_type = [:std::common_with<T, U> ? ^^std::common_type_t<T, U> : ^^void:],
		bool has_common_lt = (requires { static_cast<common_type>(xte::fake<T>()) < static_cast<common_type>(xte::fake<U>()); }),
		bool has_common_gt = (requires { static_cast<common_type>(xte::fake<U>()) > static_cast<common_type>(xte::fake<T>()); })
	>[[nodiscard]](T&& lhs, U&& rhs) static
	noexcept(are_ints
		|| XTE_IS_NOEX(XTE_FWD(lhs) < XTE_FWD(rhs))
		|| XTE_IS_NOEX(XTE_FWD(rhs) > XTE_FWD(lhs))
		|| XTE_IS_NOEX(static_cast<common_type>(XTE_FWD(lhs)) < static_cast<common_type>(XTE_FWD(rhs)))
		|| XTE_IS_NOEX(static_cast<common_type>(XTE_FWD(rhs)) > static_cast<common_type>(XTE_FWD(lhs))))
	requires(are_ints || has_lt || has_gt || has_common_lt || has_common_gt) {
		if constexpr (are_ints) {
			if constexpr (xte::is_unsigned<T> && xte::is_signed<U>) {
				if (rhs < 1) {
					return false;
				}
			} else if constexpr (xte::is_signed<T> && xte::is_unsigned<U>) {
				if (lhs < 0) {
					return true;
				}
			}
			return static_cast<common_type>(lhs) < static_cast<common_type>(rhs);
		} else if constexpr (has_lt) {
			return XTE_FWD(lhs) < XTE_FWD(rhs);
		} else if constexpr (has_gt) {
			return XTE_FWD(rhs) > XTE_FWD(lhs);
		} else if constexpr (has_common_lt) {
			return static_cast<common_type>(XTE_FWD(lhs)) < static_cast<common_type>(XTE_FWD(rhs));
		} else if constexpr (has_common_gt) {
			return static_cast<common_type>(XTE_FWD(rhs)) > static_cast<common_type>(XTE_FWD(lhs));
		} else {
			static_assert(false);
		}
	};
}

#endif
