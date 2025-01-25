#pragma once

#include "../math/exp.hpp"

namespace xieite::exp_lit {
	[[nodiscard]] constexpr auto operator""_exp(unsigned long long int n) noexcept {
		return xieite::exp(n);
	}

	[[nodiscard]] constexpr auto operator""_exp(long double n) noexcept {
		return xieite::exp(n);
	}
}
