#pragma once

#include "../pp/arrow.hpp"
#include "../trait/rm_v_referent.hpp"

namespace xieite {
	constexpr auto as_not_v_referent =
		[]<typename T>[[nodiscard]](T&& x)
		XIEITE_ARROW(const_cast<xieite::rm_v_referent<T&&>>(x));
}
