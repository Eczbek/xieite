export module xieite:bits.join;

import std;
import :bits.size;
import :types.TryUnsigned;

export namespace xieite::bits {
	template<std::integral... Integrals>
	[[nodiscard]] constexpr std::bitset<(... + xieite::bits::size<Integrals>)> join(const Integrals... values) noexcept {
		std::bitset<(... + xieite::bits::size<Integrals>)> result;
		(..., (result = (result >> xieite::bits::size<Integrals>) | (std::bitset<(... + xieite::bits::size<Integrals>)>(static_cast<xieite::types::TryUnsigned<Integrals>>(values)) << ((... + xieite::bits::size<Integrals>) - xieite::bits::size<Integrals>))));
		return result;
	}

	template<std::integral Integral, std::size_t size>
	[[nodiscard]] constexpr std::bitset<xieite::bits::size<Integral> * size> join(const std::array<Integral, size>& values) noexcept {
		std::bitset<xieite::bits::size<Integral> * size> result;
		for (const Integral value : values) {
			result = (result >> xieite::bits::size<Integral>) | (std::bitset<xieite::bits::size<Integral> * size>(static_cast<xieite::types::TryUnsigned<Integral>>(value)) << (xieite::bits::size<Integral> * (size - 1)));
		}
		return result;
	}
}
