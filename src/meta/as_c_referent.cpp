module;

#include <xieite/arrow.hpp>

export module xieite:as_c_referent;

import :set_c_referent;

export namespace xieite {
	template<bool qual = true, typename T>
	[[nodiscard]] constexpr auto as_c_referent(T x)
		XIEITE_ARROW(const_cast<xieite::set_c_referent<qual, T>>(x))
}
