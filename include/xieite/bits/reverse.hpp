#ifndef XIEITE_HEADER_BITS_REVERSE
#	define XIEITE_HEADER_BITS_REVERSE

#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <utility>
#	include "../bits/size.hpp"

namespace xieite::bits {
	template<std::integral Integral>
	[[nodiscard]] constexpr Integral reverse(const Integral value) noexcept {
		return ([]<std::size_t... i>(std::index_sequence<i...>) -> Integral {
			return (... | (((value >> i) & 1) << (xieite::bits::size<Integral> - i - 1)));
		})(std::make_index_sequence<xieite::bits::size<Integral>>());
	}

	template<std::size_t bits>
	[[nodiscard]] constexpr std::bitset<bits> reverse(const std::bitset<bits>& value) noexcept {
		return ([]<std::size_t... i>(std::index_sequence<i...>) -> std::bitset<bits> {
			return (... | (std::bitset<bits>(value[i]) << (bits - i - 1)));
		})(std::make_index_sequence<bits>());
	}
}

#endif
