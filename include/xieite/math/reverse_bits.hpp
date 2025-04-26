#ifndef DETAIL_XIEITE_HEADER_MATH_REVERSE_BITS
#	define DETAIL_XIEITE_HEADER_MATH_REVERSE_BITS
#
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include "../fn/unroll.hpp"
#	include "../math/bit_size.hpp"

namespace xieite {
	template<std::integral Int>
	[[nodiscard]] constexpr Int reverse_bits(Int x) noexcept {
		return xieite::unroll<xieite::bit_size<Int>>([x]<std::size_t... i> -> Int {
			return (... | (((x >> i) & 1) << (xieite::bit_size<Int> - i - 1)));
		});
	}

	template<std::size_t bits>
	[[nodiscard]] constexpr std::bitset<bits> reverse_bits(const std::bitset<bits>& x) noexcept {
		return xieite::unroll<bits>([&x]<std::size_t... i> -> std::bitset<bits> {
			return (... | (std::bitset<bits>(x[i]) << (bits - i - 1)));
		});
	}
}

#endif
