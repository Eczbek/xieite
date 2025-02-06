#pragma once

#include "../pp/arrow.hpp"
#include "../trait/add_v_referent.hpp"

namespace xieite {
	constexpr auto as_v_referent =
		[]<typename T>[[nodiscard]](T&& x)
		XIEITE_ARROW(const_cast<xieite::add_v_referent<T&&>>(x));
}
