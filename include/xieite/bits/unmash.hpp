#ifndef XIEITE_HEADER_BITS_UNMASH
#	define XIEITE_HAEDER_BITS_UNMASH

#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <limits>
#	include <tuple>
#	include <utility>
#	include "../bits/size.hpp"
#	include "../types/least_integer.hpp"
#	include "../types/try_unsigned.hpp"

namespace xieite::bits {
	template<std::size_t... sizes, std::size_t bits>
	requires(bits >= (... + sizes))
	[[nodiscard]] constexpr std::tuple<xieite::types::LeastInteger<sizes>...> unmash(std::bitset<bits> value) noexcept {
		std::tuple<xieite::types::LeastInteger<sizes>...> result;
		([&value, &result]<std::size_t... i>(std::index_sequence<i...>) -> void {
			(..., ([&value, &result] -> void {
				using Integral = xieite::types::LeastInteger<sizes>;
				std::get<i>(result) = static_cast<Integral>(value.to_ullong()) & (std::numeric_limits<Integral>::max() >> (xieite::bits::size<Integral> - sizes));
				value >>= sizes;
			})());
		})(std::make_index_sequence<sizeof...(sizes)>());
		return result;
	}

	template<std::integral Integral, std::size_t... sizes, std::size_t bits>
	requires(bits >= (... + sizes))
	[[nodiscard]] constexpr std::array<Integral, sizeof...(sizes)> unmash(std::bitset<bits> value) noexcept {
		return std::array<Integral, sizeof...(sizes)> {
			([&value] -> Integral {
				const Integral item = static_cast<Integral>(value.to_ullong()) & (std::numeric_limits<xieite::types::TryUnsigned<Integral>>::max() >> (xieite::bits::size<Integral> - sizes));
				value >>= sizes;
				return item;
			})()...
		};
	}
}

#endif
