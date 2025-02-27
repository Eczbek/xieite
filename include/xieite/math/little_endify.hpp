#pragma once

#include <bit>
#include <concepts>

namespace xieite {
	template<std::integral T>
	[[nodiscard]] constexpr T little_endify(T n) noexcept {
		return (std::endian::native == std::endian::big) ? std::byteswap(n) : n;
	}
}
