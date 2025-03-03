#pragma once

#include "../pp/arrow.hpp"
#include "../trait/add_c_referent.hpp"

namespace xieite {
	constexpr auto as_c_referent =
		[]<typename T>[[nodiscard]](T&& x) static
			XIEITE_ARROW(const_cast<xieite::add_c_referent<T&&>>(x));
}
