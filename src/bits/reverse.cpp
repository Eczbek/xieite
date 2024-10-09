export module xieite:bits.reverse;

import std;
import :bits.size;
import :functors.unroll;

export namespace xieite::bits {
	template<std::integral Integral>
	[[nodiscard]] constexpr Integral reverse(const Integral value) noexcept {
		return xieite::functors::unroll<xieite::bits::size<Integral>>([value]<std::size_t... i> {
			return (... | (((value >> i) & 1) << (xieite::bits::size<Integral> - i - 1)));
		});
	}

	template<std::size_t bits>
	[[nodiscard]] constexpr std::bitset<bits> reverse(const std::bitset<bits>& value) noexcept {
		return xieite::functors::unroll<bits>([&value]<std::size_t... i> {
			return (... | (std::bitset<bits>(value[i]) << (bits - i - 1)));
		});
	}
}
