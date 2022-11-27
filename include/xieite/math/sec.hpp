#pragma once
#include <cmath>
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N sec(const N value) noexcept {
		return 1 / std::cos(value);
	}
}
