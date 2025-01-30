#pragma once

#include "../pp/arrow.hpp"
#include "../trait/set_c_referent.hpp"

namespace xieite {
	template<bool qual = true, typename T>
	[[nodiscard]] constexpr auto as_c_referent(T x)
		XIEITE_ARROW(const_cast<xieite::set_c_referent<qual, T>>(x))
}
