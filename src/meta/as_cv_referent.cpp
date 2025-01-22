module;

#include <xieite/arrow.hpp>

export module xieite:as_cv_referent;

import :set_cv_referent;

export namespace xieite {
	template<bool qual = true, typename T>
	[[nodiscard]] constexpr auto as_cv_referent(T x)
		XIEITE_ARROW(const_cast<xieite::set_cv_referent<qual, T>>(x))
}
