#ifndef DETAIL_XTE_HEADER_MATH_FLIP_ORDER
#	define DETAIL_XTE_HEADER_MATH_FLIP_ORDER
#
#	include "../trait/is_order.hpp"
#	include <compare>

namespace xte {
	[[nodiscard]] constexpr auto flip_order(xte::is_order auto order) noexcept {
		if (std::is_lt(order)) {
			return decltype(order)::greater;
		}
		if (std::is_gt(order)) {
			return decltype(order)::less;
		}
		return order;
	}
}

#endif
