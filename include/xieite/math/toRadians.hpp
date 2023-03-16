#pragma once
#include <xieite/concepts/Arithmetic.hpp>
#include <xieite/math/pi.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr Number toRadians(const Number degrees) noexcept {
		return degrees * xieite::math::pi<Number> / 180.0;
	}
}
