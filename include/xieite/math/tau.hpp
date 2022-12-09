#pragma once
#include <xieite/concepts/Arithmetic.hpp> // xieite::concepts::Arithmetic
#include <xieite/math/pi.hpp> // xieite::math::pi

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	constexpr N tau = xieite::math::pi<N> * 2;
}
