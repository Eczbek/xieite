#pragma once

#include <concepts>
#include <cstddef>

namespace x4 {
	template<std::integral T>
	[[nodiscard]] constexpr T xorshift(T n, std::size_t bits) noexcept {
		return n ^ (n >> bits);
	}
}
