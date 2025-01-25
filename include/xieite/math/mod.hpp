#pragma once

#include "../math/rem.hpp"
#include "../math/sign.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T mod(T dividend, T divisor) noexcept {
		return xieite::rem(xieite::rem(dividend, divisor) + divisor * (xieite::sign(dividend) != xieite::sign(divisor)), divisor);
	}
}
