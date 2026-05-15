#ifndef DETAIL_XTE_HEADER_MATH_LESS
#	define DETAIL_XTE_HEADER_MATH_LESS
#
#	include "../meta/end.hpp"
#	include "../meta/fake.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_number.hpp"
#	include "../trait/is_unsigned.hpp"
#	include "../trait/remove_cvref.hpp"
#	include <concepts>
#	include <type_traits>

namespace xte {
	constexpr auto less =
		[]<typename T, typename U, xte::end...,
			bool are_numbers = xte::is_number<xte::remove_cvref<T>> && xte::is_number<xte::remove_cvref<U>>,
			typename common_type = [:std::common_with<T, U> ? ^^std::common_type_t<T, U> : ^^void:]>
		[[nodiscard]](T&& lhs, U&& rhs) static XTE_ARROW_FIRST(
			([](T lhs, U rhs) noexcept requires(are_numbers) {
				if constexpr (xte::is_unsigned<T> && !xte::is_unsigned<U>) {
					if (rhs < 1) {
						return false;
					}
				} else if constexpr (!xte::is_unsigned<T> && xte::is_unsigned<U>) {
					if (lhs < 0) {
						return true;
					}
				}
				if constexpr (are_numbers) {
					return static_cast<common_type>(lhs) < static_cast<common_type>(rhs);
				}
			})(lhs, rhs),
			static_cast<bool>(XTE_FWD(lhs) < XTE_FWD(rhs)),
			static_cast<bool>(XTE_FWD(rhs) > XTE_FWD(lhs)),
			static_cast<bool>(static_cast<common_type>(XTE_FWD(lhs)) < static_cast<common_type>(XTE_FWD(rhs))),
			static_cast<bool>(static_cast<common_type>(XTE_FWD(rhs)) > static_cast<common_type>(XTE_FWD(lhs)))
		);
}

#endif
