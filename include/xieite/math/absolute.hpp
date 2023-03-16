#pragma once
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr Number absolute(const Number value) noexcept {
		return ((value >= 0.0) * 2 - 1) * value;
	}
}
