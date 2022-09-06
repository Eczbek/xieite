#pragma once

#include <numbers>


namespace gcufl::numbers {
	template <typename N>
	constexpr N tau_v = std::numbers::pi_v<N> * 2;

	constexpr double tau = gcufl::numbers::tau_v<double>;
}
