#pragma once
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N absolute(const N value) noexcept {
		return ((value >= 0) * 2 - 1) * value;
	}
}
