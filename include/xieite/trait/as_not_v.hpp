#pragma once

#include "../pp/arrow.hpp"
#include "../trait/rm_v.hpp"

namespace xieite {
	constexpr auto as_not_v =
		[]<typename T>[[nodiscard]](T&& x)
			XIEITE_ARROW(const_cast<xieite::rm_v<T&&>>(x));
}
