#ifndef DETAIL_XIEITE_HEADER_MATH_UNMASH_BITS
#	define DETAIL_XIEITE_HEADER_MATH_UNMASH_BITS
#
#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <tuple>
#	include <utility>
#	include "../fn/repeat.hpp"
#	include "../math/bit_size.hpp"
#	include "../math/least_uint.hpp"
#	include "../trait/try_unsigned.hpp"

namespace xieite {
	template<std::size_t... sizes, std::size_t bits>
	requires(bits >= (... + sizes))
	[[nodiscard]] constexpr std::tuple<xieite::least_uint<sizes>...> unmash_bits(std::bitset<bits> x) noexcept {
		std::tuple<xieite::least_uint<sizes>...> result;
		xieite::repeat<sizeof...(sizes)>([&x, &result]<std::size_t i> -> void {
			using UInt = xieite::least_uint<sizes...[i]>;
			std::get<i>(result) = static_cast<UInt>(std::exchange(x, x >> sizes...[i]).to_ullong()) & (static_cast<UInt>(-1) >> (xieite::bit_size<UInt> - sizes...[i]));
		});
		return result;
	}

	template<std::integral Int, std::size_t... sizes, std::size_t bits>
	requires(bits >= (... + sizes))
	[[nodiscard]] constexpr std::array<Int, sizeof...(sizes)> unmash_bits(std::bitset<bits> x) noexcept {
		return std::array<Int, sizeof...(sizes)> {
			([&x] -> Int {
				const Int item = static_cast<Int>(x.to_ullong()) & (static_cast<xieite::try_unsigned<Int>>(-1) >> (xieite::bit_size<Int> - sizes));
				x >>= sizes;
				return item;
			})()...
		};
	}
}

#endif
