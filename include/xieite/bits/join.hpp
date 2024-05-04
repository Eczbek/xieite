#ifndef XIEITE_HEADER_BITS_JOIN
#	define XIEITE_HEADER_BITS_JOIN

#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include "../types/try_unsigned.hpp"
#	include "../types/size_bits.hpp"

namespace xieite::bits {
	template<std::integral... Integrals_>
	[[nodiscard]] constexpr std::bitset<(... + xieite::types::sizeBits<Integrals_>)> join(const Integrals_... values) noexcept {
		std::bitset<(... + xieite::types::sizeBits<Integrals_>)> result;
		(..., (result = (result >> xieite::types::sizeBits<Integrals_>) | (std::bitset<(... + xieite::types::sizeBits<Integrals_>)>(static_cast<xieite::types::TryUnsigned<Integrals_>>(values)) << ((... + xieite::types::sizeBits<Integrals_>) - xieite::types::sizeBits<Integrals_>))));
		return result;
	}

	template<std::integral Integral_, std::size_t size_>
	[[nodiscard]] constexpr std::bitset<xieite::types::sizeBits<Integral_> * size_> join(const std::array<Integral_, size_>& values) noexcept {
		std::bitset<xieite::types::sizeBits<Integral_> * size_> result;
		for (const Integral_ value : values) {
			result = (result >> xieite::types::sizeBits<Integral_>) | (std::bitset<xieite::types::sizeBits<Integral_> * size_>(static_cast<xieite::types::TryUnsigned<Integral_>>(value)) << (xieite::types::sizeBits<Integral_> * (size_ - 1)));
		}
		return result;
	}
}

#endif
