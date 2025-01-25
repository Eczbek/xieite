#pragma once

#include "../pp/arrow.hpp"
#include "../trait/set_v.hpp"

namespace xieite {
	template<bool qual = true, typename T>
	[[nodiscard]] constexpr auto as_v(T&& x)
		XIEITE_ARROW(const_cast<xieite::set_v<qual, T&&>>(x))
}
