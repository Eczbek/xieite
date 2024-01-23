#ifndef XIEITE_HEADER_MATH_BIT_MASH
#	define XIEITE_HEADER_MATH_BIT_MASH

#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <utility>
#	include "../types/maybe_unsigned.hpp"

namespace xieite::math {
	template<std::size_t... sizes, std::integral... Integers>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> bitMash(const Integers... values) noexcept {
		std::bitset<(... + sizes)> result;
		(..., (result = (result >> sizes) | (std::bitset<(... + sizes)>(static_cast<xieite::types::MaybeUnsigned<Integers>>(values)) << ((... + sizes) - sizes))));
		return result;
	}

	template<std::size_t... sizes, std::integral Integer>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> bitMash(const std::array<Integer, sizeof...(sizes)>& values) noexcept {
		return ([&values]<std::size_t... indices>(std::index_sequence<indices...>) -> std::bitset<(... + sizes)> {
			std::bitset<(... + sizes)> result;
			(..., (result = (result >> sizes) | (std::bitset<(... + sizes)>(static_cast<xieite::types::MaybeUnsigned<Integer>>(values[indices])) << ((... + sizes) - sizes))));
			return result;
		})(std::make_index_sequence<sizeof...(sizes)>());
	}
}

#endif
