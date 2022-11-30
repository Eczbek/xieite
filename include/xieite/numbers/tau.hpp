#pragma once
#include <numbers>
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::numbers {
	template<xieite::concepts::Arithmetic N>
	constexpr N tau = std::numbers::pi_v<N> * 2;
}
