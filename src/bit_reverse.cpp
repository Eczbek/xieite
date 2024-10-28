export module xieite:bit_reverse;

import std;
import :bit_size;
import :unroll;

export namespace xieite {
	template<std::integral T>
	[[nodiscard]] constexpr T bit_reverse(T value) noexcept {
		return xieite::unroll<xieite::bit_size<T>>([value]<std::size_t... i> {
			return (... | (((value >> i) & 1) << (xieite::bit_size<T> - i - 1)));
		});
	}

	template<std::size_t bits>
	[[nodiscard]] constexpr std::bitset<bits> bit_reverse(const std::bitset<bits>& value) noexcept {
		return xieite::unroll<bits>([&value]<std::size_t... i> {
			return (... | (std::bitset<bits>(value[i]) << (bits - i - 1)));
		});
	}
}
