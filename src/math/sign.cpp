module;

#include <xieite/fn.hpp>

export module xieite:sign;

import :is_arith;
import :neg;

export namespace xieite {
	template<xieite::is_arith T, xieite::is_arith... Ts>
	[[nodiscard]] constexpr int sign(T first, Ts... rest) noexcept {
		static constexpr auto get = XIEITE_FN(($0 > 0) - xieite::neg($0));
		return (get(first) * ... * get(rest));
	}
}
