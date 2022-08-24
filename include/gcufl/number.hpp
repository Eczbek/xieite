#pragma once

#include <numbers>


namespace gcufl {
	namespace number {
		template <typename N>
		constexpr N tau_v = std::numbers::pi_v<N> * 2;

		constexpr double tau = gcufl::number::tau_v<double>;
	}
}
