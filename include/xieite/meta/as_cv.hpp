#pragma once

#include "../pp/arrow.hpp"
#include "../trait/set_cv.hpp"

namespace xieite {
	template<bool qual = true, typename T>
	[[nodiscard]] constexpr auto as_cv(T&& x)
		XIEITE_ARROW(const_cast<xieite::set_cv<qual, T&&>>(x))
}
