#pragma once

#include <bitset>
#include <concepts>
#include <cstddef>
#include "../fn/unroll.hpp"
#include "../math/bit_size.hpp"

namespace xieite {
	template<std::integral T>
	[[nodiscard]] constexpr T reverse_bits(T n) noexcept {
		return xieite::unroll<xieite::bit_size<T>>([n]<std::size_t... i> -> T {
			return (... | (((n >> i) & 1) << (xieite::bit_size<T> - i - 1)));
		});
	}

	template<std::size_t bits>
	[[nodiscard]] constexpr std::bitset<bits> reverse_bits(const std::bitset<bits>& n) noexcept {
		return xieite::unroll<bits>([&n]<std::size_t... i> -> std::bitset<bits> {
			return (... | (std::bitset<bits>(n[i]) << (bits - i - 1)));
		});
	}
}
