#pragma once

#include "../pp/arrow.hpp"
#include "../trait/add_v.hpp"

namespace xieite {
	constexpr auto as_v =
		[]<typename T>[[nodiscard]](T&& x)
			XIEITE_ARROW(const_cast<xieite::add_v<T&&>>(x));
}
