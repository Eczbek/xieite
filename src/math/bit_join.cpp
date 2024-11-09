export module xieite:bit_join;

import std;
import :bit_size;
import :try_unsign;

export namespace xieite {
	template<std::integral... Ts>
	[[nodiscard]] constexpr std::bitset<(... + xieite::bit_size<Ts>)> bit_join(Ts... values) noexcept {
		std::bitset<(... + xieite::bit_size<Ts>)> result;
		(..., (result = (result >> xieite::bit_size<Ts>) | (std::bitset<(... + xieite::bit_size<Ts>)>(static_cast<xieite::try_unsign<Ts>>(values)) << ((... + xieite::bit_size<Ts>) - xieite::bit_size<Ts>))));
		return result;
	}

	template<std::integral T, std::size_t size>
	[[nodiscard]] constexpr std::bitset<xieite::bit_size<T> * size> bit_join(const std::array<T, size>& values) noexcept {
		std::bitset<xieite::bit_size<T> * size> result;
		for (T value : values) {
			result = (result >> xieite::bit_size<T>) | (std::bitset<xieite::bit_size<T> * size>(static_cast<xieite::try_unsign<T>>(value)) << (xieite::bit_size<T> * (size - 1)));
		}
		return result;
	}
}
