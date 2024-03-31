#ifndef XIEITE_HEADER_BITS_JOIN
#	define XIEITE_HEADER_BITS_JOIN

#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include "../types/maybe_unsigned.hpp"
#	include "../types/size_bits.hpp"

namespace xieite::bits {
	template<std::integral... Integrals>
	[[nodiscard]] constexpr std::bitset<(... + xieite::types::sizeBits<Integrals>)> join(const Integrals... values) noexcept {
		std::bitset<(... + xieite::types::sizeBits<Integrals>)> result;
		(..., (result = (result >> xieite::types::sizeBits<Integrals>) | (std::bitset<(... + xieite::types::sizeBits<Integrals>)>(static_cast<xieite::types::MaybeUnsigned<Integrals>>(values)) << ((... + xieite::types::sizeBits<Integrals>) - xieite::types::sizeBits<Integrals>))));
		return result;
	}

	template<std::integral Integral, std::size_t size>
	[[nodiscard]] constexpr std::bitset<xieite::types::sizeBits<Integral> * size> join(const std::array<Integral, size>& values) noexcept {
		std::bitset<xieite::types::sizeBits<Integral> * size> result;
		for (const Integral value : values) {
			result = (result >> xieite::types::sizeBits<Integral>) | (std::bitset<xieite::types::sizeBits<Integral> * size>(static_cast<xieite::types::MaybeUnsigned<Integral>>(value)) << (xieite::types::sizeBits<Integral> * (size - 1)));
		}
		return result;
	}
}

#endif
