#pragma once

#include "../math/exp.hpp"

namespace x4::explit {
	[[nodiscard]] consteval auto operator""_exp(unsigned long long int n) noexcept {
		return x4::exp(n);
	}

	[[nodiscard]] consteval auto operator""_exp(long double n) noexcept {
		return x4::exp(n);
	}
}
