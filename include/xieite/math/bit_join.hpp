#ifndef XIEITE_HEADER_MATH_BIT_JOIN
#	define XIEITE_HEADER_MATH_BIT_JOIN

#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include "../types/maybe_unsigned.hpp"
#	include "../types/size_bits.hpp"

namespace xieite::math {
	template<std::integral... Integers>
	[[nodiscard]] constexpr std::bitset<(... + xieite::types::sizeBits<Integers>)> bitJoin(const Integers... values) noexcept {
		std::bitset<(... + xieite::types::sizeBits<Integers>)> result;
		std::size_t shift = (... + xieite::types::sizeBits<Integers>);
		(..., (result |= std::bitset<(... + xieite::types::sizeBits<Integers>)>(static_cast<xieite::types::MaybeUnsigned<Integers>>(values)) << (shift -= xieite::types::sizeBits<Integers>)));
		return result;
	}
}

#endif
