#pragma once
#include <numbers>
#include <xieite/concepts/Arithmetic.hpp>
#include <xieite/numbers/pi.hpp>

namespace xieite::numbers {
	template<xieite::concepts::Arithmetic N>
	constexpr N tau = xieite::numbers::pi<N> * 2;
}
