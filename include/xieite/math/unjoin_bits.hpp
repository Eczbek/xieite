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
	template<std::integral... Ts, std::size_t bits>
	requires(bits >= (... + xieite::bit_size<Ts>))
	[[nodiscard]] constexpr std::tuple<Ts...> unjoin_bits(std::bitset<bits> n) noexcept {
		std::tuple<Ts...> result;
		xieite::repeat<Ts...>([&n, &result]<std::size_t i> -> void {
			std::get<i>(result) = static_cast<Ts...[i]>(n.to_ullong());
			n >>= xieite::bit_size<Ts...[i]>;
		});
		return result;
	}

	template<std::integral T, std::size_t size, std::size_t bits>
	requires(bits >= (xieite::bit_size<T> * size))
	[[nodiscard]] constexpr std::array<T, size> unjoin_bits(std::bitset<bits> n) noexcept {
		std::array<T, size> result;
		for (std::size_t i = 0; i < size; ++i) {
			result[i] = static_cast<T>(n.to_ullong());
			n >>= xieite::bit_size<T>;
		}
		return result;
	}
}

#endif
