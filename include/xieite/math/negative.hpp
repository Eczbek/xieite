#pragma once

#include <concepts>
#include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool negative(const Arithmetic value) noexcept {
		if constexpr (!std::unsigned_integral<Arithmetic>) {
			return value < 0;
		}
		return false;
	}
}
