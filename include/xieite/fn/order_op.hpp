#ifndef DETAIL_XIEITE_HEADER_FN_ORDER_OP
#	define DETAIL_XIEITE_HEADER_FN_ORDER_OP
#
#	include <compare>
#	include "../trait/is_order.hpp"

namespace xieite::order_op {
	template<xieite::is_order Order>
	[[nodiscard]] constexpr Order operator&(Order l, Order r) noexcept {
		return !std::is_eq(l) && !std::is_eq(r);
	}

	template<xieite::is_order Order>
	[[nodiscard]] constexpr Order operator|(Order l, Order r) noexcept {
		return std::is_eq(l) ? r : l;
	}
}

#endif
