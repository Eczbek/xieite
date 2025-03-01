#pragma once

#include "../math/rem.hpp"
#include "../math/sign.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T mod(T a, T b) noexcept {
		return x4::rem(x4::rem(a, b) + b * (x4::sign(a) != x4::sign(b)), b);
	}
}
