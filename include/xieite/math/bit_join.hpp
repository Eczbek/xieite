#ifndef XIEITE_HEADER_MATH_BIT_JOIN
#	define XIEITE_HEADER_MATH_BIT_JOIN

#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include "../types/maybe_unsigned.hpp"
#	include "../types/size_bits.hpp"

namespace xieite::math {
	template<std::integral... Integers>
	[[nodiscard]] constexpr std::bitset<(... + xieite::types::sizeBits<Integers>)> bitJoin(const Integers... values) noexcept {
		std::bitset<(... + xieite::types::sizeBits<Integers>)> result;
		(..., (result = (result >> xieite::types::sizeBits<Integers>) | (std::bitset<(... + xieite::types::sizeBits<Integers>)>(static_cast<xieite::types::MaybeUnsigned<Integers>>(values)) << ((... + xieite::types::sizeBits<Integers>) - xieite::types::sizeBits<Integers>))));
		return result;
	}

	template<std::integral Integer, std::size_t size>
	[[nodiscard]] constexpr std::bitset<xieite::types::sizeBits<Integer> * size> bitJoin(const std::array<Integer, size>& values) noexcept {
		std::bitset<xieite::types::sizeBits<Integer> * size> result;
		for (const Integer value : values) {
			result = (result >> xieite::types::sizeBits<Integer>) | (std::bitset<xieite::types::sizeBits<Integer> * size>(static_cast<xieite::types::MaybeUnsigned<Integer>>(value)) << (xieite::types::sizeBits<Integer> * (size - 1)));
		}
		return result;
	}
}

#endif
