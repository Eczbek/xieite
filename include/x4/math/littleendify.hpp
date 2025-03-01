#pragma once

#include <bit>
#include <concepts>

namespace x4 {
	template<std::integral T>
	[[nodiscard]] constexpr T littleendify(T n) noexcept {
		return (std::endian::native == std::endian::big) ? std::byteswap(n) : n;
	}
}
