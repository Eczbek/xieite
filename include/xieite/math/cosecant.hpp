#pragma once
#include <cmath> // std::sin
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr Number cosecant(const Number value) noexcept {
		return 1.0 / std::sin(value);
	}
}
