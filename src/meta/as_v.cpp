module;

#include <xieite/arrow.hpp>

export module xieite:as_v;

import :set_v;

export namespace xieite {
	template<bool qual = true, typename T>
	[[nodiscard]] constexpr auto as_v(T&& x)
		XIEITE_ARROW(const_cast<xieite::set_v<qual, T&&>>(x))
}
