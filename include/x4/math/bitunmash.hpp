#pragma once

#include <array>
#include <bitset>
#include <concepts>
#include <cstddef>
#include <tuple>
#include <utility>
#include "../fn/rpt.hpp"
#include "../math/bits.hpp"
#include "../math/uleast.hpp"
#include "../meta/tryunsign.hpp"

namespace x4 {
	template<std::size_t... sizes, std::size_t bits>
	requires(bits >= (... + sizes))
	[[nodiscard]] constexpr std::tuple<x4::uleast<sizes>...> bitunmash(std::bitset<bits> n) noexcept {
		std::tuple<x4::uleast<sizes>...> result;
		x4::rpt<sizeof...(sizes)>([&n, &result]<std::size_t i> -> void {
			using T = x4::uleast<sizes...[i]>;
			std::get<i>(result) = static_cast<T>(std::exchange(n, n >> sizes...[i]).to_ullong()) & (static_cast<T>(-1) >> (x4::bits<T> - sizes...[i]));
		});
		return result;
	}

	template<std::integral T, std::size_t... sizes, std::size_t bits>
	requires(bits >= (... + sizes))
	[[nodiscard]] constexpr std::array<T, sizeof...(sizes)> bitunmash(std::bitset<bits> n) noexcept {
		return std::array<T, sizeof...(sizes)> {
			([&n] -> T {
				const T item = static_cast<T>(n.to_ullong()) & (static_cast<x4::tryunsign<T>>(-1) >> (x4::bits<T> - sizes));
				n >>= sizes;
				return item;
			})()...
		};
	}
}
