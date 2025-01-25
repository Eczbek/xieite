#pragma once

#include "../pp/arrow.hpp"
#include "../trait/set_v_referent.hpp"

namespace xieite {
	template<bool qual = true, typename T>
	[[nodiscard]] constexpr auto as_v_referent(T x)
		XIEITE_ARROW(const_cast<xieite::set_v_referent<qual, T>>(x))
}
