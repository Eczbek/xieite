#ifndef XIEITE_HEADER_MATH_BIT_MASH
#	define XIEITE_HEADER_MATH_BIT_MASH

#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include "../types/maybe_unsigned.hpp"

namespace xieite::math {
	template<std::size_t... sizes, std::integral... Integers>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> bitMash(const Integers... values) noexcept {
		static constexpr std::size_t bits = (... + sizes);
		std::bitset<bits> result;
		std::size_t shift = bits;
		(..., (result |= std::bitset<bits>(static_cast<xieite::types::MaybeUnsigned<Integers>>(values)) << (shift -= sizes)));
		return result;
	}

	template<std::size_t... sizes, std::integral Integer>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> bitMash(const std::array<Integer, sizeof...(sizes)>& values) noexcept {
		static constexpr std::size_t bits = (... + sizes);
		std::bitset<bits> result;
		std::size_t shift = bits;
		std::size_t i = 0;
		(..., (result |= std::bitset<bits>(static_cast<xieite::types::MaybeUnsigned<Integer>>(values[i++])) << (shift -= sizes)));
		return result;
	}
}

#endif
