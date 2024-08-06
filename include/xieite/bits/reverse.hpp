#ifndef XIEITE_HEADER_BITS_REVERSE
#	define XIEITE_HEADER_BITS_REVERSE

#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <utility>
#	include "../bits/size.hpp"

namespace xieite::bits {
	template<std::integral Integral_>
	[[nodiscard]] constexpr Integral_ reverse(const Integral_ value) noexcept {
		return ([]<std::size_t... i_>(std::index_sequence<i_...>) {
			return (... | (((value >> i_) & 1) << (xieite::bits::size<Integral_> - i_ - 1)));
		})(std::make_index_sequence<xieite::bits::size<Integral_>>());
	}

	template<std::size_t bits_>
	[[nodiscard]] constexpr std::bitset<bits_> reverse(const std::bitset<bits_>& value) noexcept {
		return ([]<std::size_t... i_>(std::index_sequence<i_...>) {
			return (... | (std::bitset<bits_>(value[i_]) << (bits_ - i_ - 1)));
		})(std::make_index_sequence<bits_>());
	}
}

#endif
