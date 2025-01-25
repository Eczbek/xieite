#pragma once

#include <bit>
#include <concepts>

namespace xieite {
	template<std::integral T>
	[[nodiscard]] constexpr T big_endify(T n) noexcept {
		return (std::endian::native == std::endian::little) ? std::byteswap(n) : n;
	}
}
