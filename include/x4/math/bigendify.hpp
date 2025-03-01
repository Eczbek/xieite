#pragma once

#include <bit>
#include <concepts>

namespace x4 {
	template<std::integral T>
	[[nodiscard]] constexpr T bigendify(T n) noexcept {
		return (std::endian::native == std::endian::little) ? std::byteswap(n) : n;
	}
}
