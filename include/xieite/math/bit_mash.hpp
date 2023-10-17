#ifndef XIEITE_HEADER_MATH_BIT_MASH
#	define XIEITE_HEADER_MATH_BIT_MASH

#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include "../types/maybe_unsigned.hpp"

namespace xieite::math {
	template<std::size_t... sizes, std::integral... Integers>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> bitMash(const Integers... values) noexcept {
		std::bitset<(... + sizes)> result;
		std::size_t shift = (... + sizes);
		(..., (result |= std::bitset<(... + sizes)>(static_cast<xieite::types::MaybeUnsigned<Integers>>(values)) << (shift -= sizes)));
		return result;
	}
}

#endif
