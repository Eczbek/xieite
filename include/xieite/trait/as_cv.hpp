#pragma once

#include "../pp/arrow.hpp"
#include "../trait/add_cv.hpp"

namespace xieite {
	constexpr auto as_cv =
		[]<typename T>[[nodiscard]](T&& x)
		XIEITE_ARROW(const_cast<xieite::add_cv<T&&>>(x));
}
