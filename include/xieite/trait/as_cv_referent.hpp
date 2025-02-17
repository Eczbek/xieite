#pragma once

#include "../pp/arrow.hpp"
#include "../trait/add_cv_referent.hpp"

namespace xieite {
	constexpr auto as_cv_referent =
		[]<typename T>[[nodiscard]](T&& x)
			XIEITE_ARROW(const_cast<xieite::add_cv_referent<T&&>>(x));
}
