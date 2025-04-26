#ifndef DETAIL_XIEITE_HEADER_MATH_UNJOIN_BITS
#	define DETAIL_XIEITE_HEADER_MATH_UNJOIN_BITS
#
#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <tuple>
#	include "../fn/repeat.hpp"
#	include "../math/bit_size.hpp"

namespace xieite {
	template<std::integral... Ints, std::size_t bits>
	requires(bits >= (... + xieite::bit_size<Ints>))
	[[nodiscard]] constexpr std::tuple<Ints...> unjoin_bits(std::bitset<bits> x) noexcept {
		std::tuple<Ints...> result;
		xieite::repeat<Ints...>([&x, &result]<std::size_t i> -> void {
			std::get<i>(result) = static_cast<Ints...[i]>(x.to_ullong());
			x >>= xieite::bit_size<Ints...[i]>;
		});
		return result;
	}

	template<std::integral Int, std::size_t size, std::size_t bits>
	requires(bits >= (xieite::bit_size<Int> * size))
	[[nodiscard]] constexpr std::array<Int, size> unjoin_bits(std::bitset<bits> x) noexcept {
		std::array<Int, size> result;
		for (std::size_t i = 0; i < size; ++i) {
			result[i] = static_cast<Int>(x.to_ullong());
			x >>= xieite::bit_size<Int>;
		}
		return result;
	}
}

#endif
