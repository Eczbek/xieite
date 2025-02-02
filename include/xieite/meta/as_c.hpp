#pragma once

#include "../pp/arrow.hpp"
#include "../trait/set_c.hpp"

namespace xieite {
	template<bool qual = true, typename T>
	[[nodiscard]] constexpr auto as_c(T&& x)
		XIEITE_ARROW(const_cast<xieite::set_c<qual, T&&>>(x))
}
