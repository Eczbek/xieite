#pragma once

#include "../pp/arrow.hpp"
#include "../trait/rm_cv.hpp"

namespace xieite {
	constexpr auto as_not_cv =
		[]<typename T>[[nodiscard]](T&& x)
			XIEITE_ARROW(const_cast<xieite::rm_cv<T&&>>(x));
}
