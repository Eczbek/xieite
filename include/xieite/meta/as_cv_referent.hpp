#pragma once

#include "../pp/arrow.hpp"
#include "../trait/set_cv_referent.hpp"

namespace xieite {
	template<bool qual = true, typename T>
	[[nodiscard]] constexpr auto as_cv_referent(T x)
		XIEITE_ARROW(const_cast<xieite::set_cv_referent<qual, T>>(x))
}
