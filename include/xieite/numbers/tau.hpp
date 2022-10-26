#pragma once
#include <numbers>

namespace xieite::numbers {
	template<typename N = double>
	constexpr N tau = std::numbers::pi_v<N> * 2;
}
