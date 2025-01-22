export module xieite:order_op;

import std;
import :is_order;

export namespace xieite::order_op {
	template<xieite::is_order Order>
	[[nodiscard]] constexpr Order operator&(Order l, Order r) noexcept {
		return !std::is_eq(l) && !std::is_eq(r);
	}

	template<xieite::is_order Order>
	[[nodiscard]] constexpr Order operator|(Order l, Order r) noexcept {
		return std::is_eq(l) ? r : l;
	}
}
