#pragma once

#include "../concepts/numeric.hpp"
#include "../math/sign.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric... Numbers>
	[[nodiscard]] constexpr int productSign(const Numbers... values) noexcept {
		return (... * xieite::math::sign(values));
	}
}
