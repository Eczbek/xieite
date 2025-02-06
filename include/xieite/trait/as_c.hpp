#pragma once

#include "../pp/arrow.hpp"
#include "../trait/add_c.hpp"

namespace xieite {
	constexpr auto as_c =
		[]<typename T>[[nodiscard]](T&& x)
		XIEITE_ARROW(const_cast<xieite::add_c<T&&>>(x));
}
