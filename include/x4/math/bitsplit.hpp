#pragma once

#include <array>
#include <bitset>
#include <concepts>
#include <cstddef>
#include <tuple>
#include "../fn/rpt.hpp"
#include "../math/bits.hpp"

namespace x4 {
	template<std::integral... Ts, std::size_t bits>
	requires(bits >= (... + x4::bits<Ts>))
	[[nodiscard]] constexpr std::tuple<Ts...> bitsplit(std::bitset<bits> n) noexcept {
		std::tuple<Ts...> result;
		x4::rpt<Ts...>([&n, &result]<std::size_t i> -> void {
			std::get<i>(result) = static_cast<Ts...[i]>(n.to_ullong());
			n >>= x4::bits<Ts...[i]>;
		});
		return result;
	}

	template<std::integral T, std::size_t size, std::size_t bits>
	requires(bits >= (x4::bits<T> * size))
	[[nodiscard]] constexpr std::array<T, size> bitsplit(std::bitset<bits> n) noexcept {
		std::array<T, size> result;
		for (std::size_t i = 0; i < size; ++i) {
			result[i] = static_cast<T>(n.to_ullong());
			n >>= x4::bits<T>;
		}
		return result;
	}
}
