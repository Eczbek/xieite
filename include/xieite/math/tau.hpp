#pragma once

#include "../math/pi.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	constexpr T tau = xieite::pi<T> * 2;
}
