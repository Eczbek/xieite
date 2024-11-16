export module xieite:bit_mash;

import std;
import :try_unsign;
import :unroll;

export namespace xieite {
	template<std::size_t... sizes, std::integral... Ts>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> bit_mash(Ts... values) noexcept {
		static constexpr std::size_t bits = (... + sizes);
		std::bitset<bits> result;
		(..., (result = (result >> sizes) | (std::bitset<bits>(static_cast<xieite::try_unsign<Ts>>(values)) << (bits - sizes))));
		return result;
	}

	template<std::size_t... sizes, std::integral T>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> bit_mash(const std::array<T, sizeof...(sizes)>& values) noexcept {
		static constexpr std::size_t bits = (... + sizes);
		std::bitset<bits> result;
		xieite::unroll<sizeof...(sizes)>([&values, &result]<std::size_t... i> -> void {
			(..., (result = (result >> sizes) | (std::bitset<bits>(static_cast<xieite::try_unsign<T>>(values[i])) << (bits - sizes))));
		});
		return result;
	}
}
