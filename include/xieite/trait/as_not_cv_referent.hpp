#pragma once

#include "../pp/arrow.hpp"
#include "../trait/rm_cv_referent.hpp"

namespace xieite {
	constexpr auto as_not_cv_referent =
		[]<typename T>[[nodiscard]](T&& x)
			XIEITE_ARROW(const_cast<xieite::rm_cv_referent<T&&>>(x));
}
