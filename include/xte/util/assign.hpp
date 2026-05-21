#ifndef DETAIL_XTE_HEADER_UTIL_ASSIGN
#	define DETAIL_XTE_HEADER_UTIL_ASSIGN
#
#	include "../meta/end.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_number.hpp"
#	include "../trait/remove_cvref.hpp"
#	include "../util/cast.hpp"
#	include "../util/reconstruct.hpp"
#	include <utility>

namespace xte {
	template<typename T, typename U, xte::end...,
		bool are_numbers = xte::is_number<xte::remove_cvref<T>> && xte::is_number<xte::remove_cvref<U>>>
	constexpr auto assign(T&& lhs, U&& rhs) XTE_ARROW_FIRST(
		([](T& lhs, U rhs) noexcept -> T& requires(are_numbers) {
			if constexpr (are_numbers) {
				return lhs = xte::cast<xte::remove_cvref<T>>(rhs);
			}
			std::unreachable();
		})(lhs, rhs),
		XTE_FWD(lhs) = XTE_FWD(rhs),
		XTE_FWD(lhs) = xte::cast<xte::remove_cvref<decltype(lhs)>>(XTE_FWD(rhs)),
		xte::reconstruct(lhs, XTE_FWD(rhs)),
		xte::reconstruct(lhs, xte::cast<xte::remove_cvref<decltype(lhs)>>(XTE_FWD(rhs)))
	)

	constexpr auto assign(auto&& lhs) XTE_ARROW_FIRST(
		XTE_FWD(lhs) = xte::remove_cvref<decltype(lhs)>(),
		xte::reconstruct(lhs)
	)
}

#endif
