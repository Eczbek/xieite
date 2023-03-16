#pragma once
#include <cmath> // std::cos, std::sin
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr Number cotangent(const Number value) noexcept {
		return std::cos(value) / std::sin(value);
	}
}
