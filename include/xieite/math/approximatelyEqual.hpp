#pragma once

#include <limits>
#include <xieite/concepts/Arithmetic.hpp>
#include <xieite/math/absolute.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr bool approximatelyEqual(const Number value1, const Number value2) noexcept {
		return xieite::math::absolute(value1 - value2) <= std::numeric_limits<Number>::epsilon();
	}
}
