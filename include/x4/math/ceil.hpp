#pragma once

#include "../math/divceil.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T ceil(T n, T step = 1) noexcept {
		return x4::divceil(n, step) * step;
	}
}
