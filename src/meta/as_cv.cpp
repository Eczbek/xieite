module;

#include <xieite/arrow.hpp>

export module xieite:as_cv;

import :set_cv;

export namespace xieite {
	template<bool qual = true, typename T>
	[[nodiscard]] constexpr auto as_cv(T&& x)
		XIEITE_ARROW(const_cast<xieite::set_cv<qual, T&&>>(x))
}
