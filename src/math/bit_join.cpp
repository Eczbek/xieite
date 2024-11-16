export module xieite:bit_join;

import std;
import :bit_size;
import :try_unsign;

export namespace xieite {
	template<std::integral... Ts,
		std::size_t bits = (... + xieite::bit_size<Ts>)>
	[[nodiscard]] constexpr std::bitset<bits> bit_join(Ts... values) noexcept {
		std::bitset<bits> result;
		(..., (result = (result >> xieite::bit_size<Ts>) | (std::bitset<bits>(static_cast<xieite::try_unsign<Ts>>(values)) << (bits - xieite::bit_size<Ts>))));
		return result;
	}

	template<std::integral T, std::size_t size>
	[[nodiscard]] constexpr std::bitset<xieite::bit_size<T> * size> bit_join(const std::array<T, size>& values) noexcept {
		static constexpr std::size_t bits = xieite::bit_size<T> * size;
		std::bitset<bits> result;
		for (T value : values) {
			result = (result >> xieite::bit_size<T>) | (std::bitset<bits>(static_cast<xieite::try_unsign<T>>(value)) << (bits - xieite::bit_size<T>));
		}
		return result;
	}
}
