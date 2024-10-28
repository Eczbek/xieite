export module xieite:bit_mash;

import std;
import :unroll;
import :try_unsigned;

export namespace xieite {
	template<std::size_t... sizes, std::integral... Ts>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> bit_mash(Ts... values) noexcept {
		std::bitset<(... + sizes)> result;
		(..., (result = (result >> sizes) | (std::bitset<(... + sizes)>(static_cast<xieite::try_unsigned<Ts>>(values)) << ((... + sizes) - sizes))));
		return result;
	}

	template<std::size_t... sizes, std::integral T>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> bit_mash(const std::array<T, sizeof...(sizes)>& values) noexcept {
		std::bitset<(... + sizes)> result;
		xieite::unroll<sizeof...(sizes)>([&values, &result]<std::size_t... i> {
			(..., (result = (result >> sizes) | (std::bitset<(... + sizes)>(static_cast<xieite::try_unsigned<T>>(values[i])) << ((... + sizes) - sizes))));
		});
		return result;
	}
}
