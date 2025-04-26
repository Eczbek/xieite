#ifndef DETAIL_XIEITE_HEADER_MATH_JOIN_BITS
#	define DETAIL_XIEITE_HEADER_MATH_JOIN_BITS
#
#	include <array>
#	include <bitset>
#	include <concepts>
#	include "../math/bit_size.hpp"
#	include "../trait/try_unsigned.hpp"

namespace xieite {
	template<std::integral... Ints>
	[[nodiscard]] constexpr std::bitset<(... + xieite::bit_size<Ints>)> join_bits(Ints... args) noexcept {
		static constexpr std::size_t bits = (... + xieite::bit_size<Ints>);
		std::bitset<bits> result;
		(..., (result = (result >> xieite::bit_size<Ints>) | (std::bitset<bits>(static_cast<xieite::try_unsigned<Ints>>(args)) << (bits - xieite::bit_size<Ints>))));
		return result;
	}

	template<std::integral Int, std::size_t size>
	[[nodiscard]] constexpr std::bitset<(xieite::bit_size<Int> * size)> join_bits(const std::array<Int, size>& args) noexcept {
		static constexpr std::size_t bits = xieite::bit_size<Int> * size;
		std::bitset<bits> result;
		for (Int n : args) {
			result = (result >> xieite::bit_size<Int>) | (std::bitset<bits>(static_cast<xieite::try_unsigned<Int>>(n)) << (bits - xieite::bit_size<Int>));
		}
		return result;
	}
}

#endif
