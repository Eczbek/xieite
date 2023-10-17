#ifndef XIEITE_HEADER_MATH_BIT_MASH
#	define XIEITE_HEADER_MATH_BIT_MASH

#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include "../types/size_bits.hpp"

namespace xieite::math {
	template<std::integral... Integers>
	[[nodiscard]] constexpr std::bitset<(... + xieite::types::sizeBits<Integers>)> bitMash(const Integers... values) noexcept {
		std::bitset<(... + xieite::types::sizeBits<Integers>)> result;
		std::size_t shift = (... + xieite::types::sizeBits<Integers>);
		(..., (result |= std::bitset<(... + xieite::types::sizeBits<Integers>)>(static_cast<unsigned long long int>(values)) << (shift -= xieite::types::sizeBits<Integers>)));
		return result;
	}
}

#endif