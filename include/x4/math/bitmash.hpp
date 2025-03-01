#pragma once

#include <bitset>
#include <concepts>
#include <cstddef>
#include "../fn/unroll.hpp"
#include "../meta/tryunsign.hpp"

namespace x4 {
	template<std::size_t... sizes, std::integral... Ts>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> bitmash(Ts... args) noexcept {
		static constexpr std::size_t bits = (... + sizes);
		std::bitset<bits> result;
		(..., (result = (result >> sizes) | (std::bitset<bits>(static_cast<x4::tryunsign<Ts>>(args)) << (bits - sizes))));
		return result;
	}

	template<std::size_t... sizes, std::integral T>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> bitmash(const std::array<T, sizeof...(sizes)>& args) noexcept {
		static constexpr std::size_t bits = (... + sizes);
		std::bitset<bits> result;
		x4::unroll<sizeof...(sizes)>([&args, &result]<std::size_t... i> -> void {
			(..., (result = (result >> sizes) | (std::bitset<bits>(static_cast<x4::tryunsign<T>>(args[i])) << (bits - sizes))));
		});
		return result;
	}
}
