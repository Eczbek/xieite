#pragma once

#include "../pp/arrow.hpp"
#include "../trait/rm_c_referent.hpp"

namespace xieite {
	constexpr auto as_not_c_referent =
		[]<typename T>[[nodiscard]](T&& x)
		XIEITE_ARROW(const_cast<xieite::rm_c_referent<T&&>>(x));
}
