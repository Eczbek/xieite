#pragma once

#include "../pp/arrow.hpp"
#include "../trait/rm_c.hpp"

namespace xieite {
	constexpr auto as_not_c =
		[]<typename T>[[nodiscard]](T&& x)
		XIEITE_ARROW(const_cast<xieite::rm_c<T&&>>(x));
}
