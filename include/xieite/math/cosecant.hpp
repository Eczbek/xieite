#pragma once
#include <cmath> // std::sin
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N cosecant(const N value) noexcept {
		return 1 / std::sin(value);
	}
}
