module;

#include <xieite/arrow.hpp>

export module xieite:as_c;

import :set_c;

export namespace xieite {
	template<bool qual = true, typename T>
	[[nodiscard]] constexpr auto as_c(T&& x)
		XIEITE_ARROW(const_cast<xieite::set_c<qual, T&&>>(x))
}
