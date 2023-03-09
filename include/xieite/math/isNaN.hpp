#pragma once
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr bool isNaN(const N value) noexcept {
		return value != value;
	}
}
