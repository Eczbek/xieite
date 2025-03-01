#pragma once

#include <bitset>
#include <concepts>
#include <cstddef>
#include "../fn/unroll.hpp"
#include "../math/bits.hpp"

namespace x4 {
	template<std::integral T>
	[[nodiscard]] constexpr T bitrvs(T n) noexcept {
		return x4::unroll<x4::bits<T>>([n]<std::size_t... i> -> T {
			return (... | (((n >> i) & 1) << (x4::bits<T> - i - 1)));
		});
	}

	template<std::size_t bits>
	[[nodiscard]] constexpr std::bitset<bits> bitrvs(const std::bitset<bits>& n) noexcept {
		return x4::unroll<bits>([&n]<std::size_t... i> -> std::bitset<bits> {
			return (... | (std::bitset<bits>(n[i]) << (bits - i - 1)));
		});
	}
}
