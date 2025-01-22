module;

#include <xieite/arrow.hpp>

export module xieite:as_v_referent;

import :set_v_referent;

export namespace xieite {
	template<bool qual = true, typename T>
	[[nodiscard]] constexpr auto as_v_referent(T x)
		XIEITE_ARROW(const_cast<xieite::set_v_referent<qual, T>>(x))
}
