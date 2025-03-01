#pragma once

#include <cmath>
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T, x4::isarith U = std::common_type_t<T, double>>
	[[nodiscard]] constexpr U log(T base, T n) noexcept {
		return static_cast<U>(std::log(n) / std::log(base));
	}
}
