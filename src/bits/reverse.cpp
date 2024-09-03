export module xieite:bits.reverse;

import std;
import :bits.size;

export namespace xieite::bits {
	template<std::integral Integral>
	[[nodiscard]] constexpr Integral reverse(const Integral value) noexcept {
		return ([value]<std::size_t... i>(std::index_sequence<i...>) -> Integral {
			return (... | (((value >> i) & 1) << (xieite::bits::size<Integral> - i - 1)));
		})(std::make_index_sequence<xieite::bits::size<Integral>>());
	}

	template<std::size_t bits>
	[[nodiscard]] constexpr std::bitset<bits> reverse(const std::bitset<bits>& value) noexcept {
		return ([&value]<std::size_t... i>(std::index_sequence<i...>) -> std::bitset<bits> {
			return (... | (std::bitset<bits>(value[i]) << (bits - i - 1)));
		})(std::make_index_sequence<bits>());
	}
}
