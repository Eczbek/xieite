#pragma once

#include <bitset>
#include <concepts>
#include <cstddef>
#include "../fn/unroll.hpp"
#include "../trait/try_unsign.hpp"

namespace xieite {
	template<std::size_t... sizes, std::integral... Ts>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> mash_bits(Ts... args) noexcept {
		static constexpr std::size_t bits = (... + sizes);
		std::bitset<bits> result;
		(..., (result = (result >> sizes) | (std::bitset<bits>(static_cast<xieite::try_unsign<Ts>>(args)) << (bits - sizes))));
		return result;
	}

	template<std::size_t... sizes, std::integral T>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> mash_bits(const std::array<T, sizeof...(sizes)>& args) noexcept {
		static constexpr std::size_t bits = (... + sizes);
		std::bitset<bits> result;
		xieite::unroll<sizeof...(sizes)>([&args, &result]<std::size_t... i> -> void {
			(..., (result = (result >> sizes) | (std::bitset<bits>(static_cast<xieite::try_unsign<T>>(args[i])) << (bits - sizes))));
		});
		return result;
	}
}
