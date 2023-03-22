#pragma once

#include <xieite/concepts/Arithmetic.hpp>
#include <xieite/math/pi.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	constexpr Number tau = xieite::math::pi<Number> * 2.0;
}
