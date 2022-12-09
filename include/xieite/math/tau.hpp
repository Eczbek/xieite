#pragma once
#include <xieite/concepts/Arithmetic.hpp>
#include <xieite/math/pi.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	constexpr N tau = xieite::math::pi<N> * 2;
}
