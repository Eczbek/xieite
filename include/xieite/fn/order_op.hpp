#ifndef DETAIL_XIEITE_HEADER_FN_ORDER_OP
#	define DETAIL_XIEITE_HEADER_FN_ORDER_OP
#
#	include <compare>
#	include "../trait/is_order.hpp"

namespace xieite::order_op {
	template<xieite::is_order Order>
	[[nodiscard]] constexpr Order operator&&(Order lhs, Order rhs) noexcept {
		return !std::is_eq(lhs) && !std::is_eq(rhs);
	}

	template<xieite::is_order Order>
	[[nodiscard]] constexpr Order operator||(Order lhs, Order rhs) noexcept {
		return std::is_eq(lhs) ? rhs : lhs;
	}
}

#endif
