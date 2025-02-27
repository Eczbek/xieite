#pragma once

#include "../math/exp.hpp"

namespace xieite::exp_lit {
	[[nodiscard]] consteval auto operator""_exp(unsigned long long int n) noexcept {
		return xieite::exp(n);
	}

	[[nodiscard]] consteval auto operator""_exp(long double n) noexcept {
		return xieite::exp(n);
	}
}
