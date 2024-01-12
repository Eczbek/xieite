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
		static constexpr std::size_t bits = (... + xieite::types::sizeBits<Integers>);
		std::bitset<bits> result;
		std::size_t shift = bits;
		(..., (result |= std::bitset<bits>(static_cast<xieite::types::MaybeUnsigned<Integers>>(values)) << (shift -= xieite::types::sizeBits<Integers>)));
		return result;
	}

	template<std::integral Integer, std::size_t size>
	[[nodiscard]] constexpr std::bitset<xieite::types::sizeBits<Integer> * size> bitJoin(const std::array<Integer, size>& values) noexcept {
		static constexpr std::size_t bits = xieite::types::sizeBits<Integer> * size;
		std::bitset<bits> result;
		std::size_t shift = bits;
		for (const Integer value : values) {
			shift -= xieite::types::sizeBits<Integer>;
			result |= std::bitset<bits>(static_cast<xieite::types::MaybeUnsigned<Integer>>(value)) << shift;
		}
		return result;
	}
}

#endif
