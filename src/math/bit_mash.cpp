export module xieite:bit_mash;

import std;
import :end;
import :try_unsign;
import :unroll;

export namespace xieite {
	template<std::size_t... sizes, std::integral... Ts,
		std::size_t bits = (... + sizes)>
	[[nodiscard]] constexpr std::bitset<bits> bit_mash(Ts... values) noexcept {
		std::bitset<bits> result;
		(..., (result = (result >> sizes) | (std::bitset<bits>(static_cast<xieite::try_unsign<Ts>>(values)) << (bits - sizes))));
		return result;
	}

	template<std::size_t... sizes, std::integral T,
		std::size_t bits = (... + sizes)>
	[[nodiscard]] constexpr std::bitset<bits> bit_mash(const std::array<T, sizeof...(sizes)>& values) noexcept {
		std::bitset<bits> result;
		xieite::unroll<sizeof...(sizes)>([&values, &result]<std::size_t... i> -> void {
			(..., (result = (result >> sizes) | (std::bitset<bits>(static_cast<xieite::try_unsign<T>>(values[i])) << (bits - sizes))));
		});
		return result;
	}
}
