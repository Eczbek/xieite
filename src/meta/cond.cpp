module;

#include <xieite/fwd.hpp>

export module xieite:cond;

export namespace xieite {
	template<bool value>
	[[nodiscard]] constexpr auto&& cond(auto&& left, auto&& right) noexcept {
		if constexpr (value) {
			return XIEITE_FWD(left);
		} else {
			return XIEITE_FWD(right);
		}
	}

	template<bool value>
	constexpr decltype(auto) cond(auto&& left) noexcept {
		if constexpr (value) {
			return XIEITE_FWD(left);
		}
	}
}
