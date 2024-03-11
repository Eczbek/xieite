#ifndef XIEITE_HEADER_BITS_UNMASH
#	define XIEITE_HAEDER_BITS_UNMASH

#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <limits>
#	include <tuple>
#	include "../containers/reverse_tuple.hpp"
#	include "../types/least_integer.hpp"
#	include "../types/maybe_unsigned.hpp"

namespace xieite::bits {
	template<std::size_t... sizes>
	[[nodiscard]] constexpr std::tuple<xieite::types::LeastInteger<sizes>...> unmash(std::bitset<(... + sizes)> value) noexcept {
		return xieite::containers::reverseTuple(std::make_tuple<xieite::types::LeastInteger<sizes>...>(([&value] -> xieite::types::LeastInteger<sizes> {
			using Integer = xieite::types::LeastInteger<sizes>;
			Integer item = static_cast<Integer>(value.to_ullong());
			if constexpr (sizes < xieite::types::sizeBits<Integer>) {
				item &= std::numeric_limits<Integer>::max() >> (xieite::types::sizeBits<Integer> - sizes);
			}
			value >>= sizes;
			return item;
		})()...));
	}

	template<std::integral Integer, std::size_t... sizes>
	[[nodiscard]] constexpr std::array<Integer, sizeof...(sizes)> unmash(std::bitset<(... + sizes)> value) noexcept {
		return std::array<Integer, sizeof...(sizes)> {
			([&value] -> Integer {
				Integer item = static_cast<Integer>(value.to_ullong());
				if constexpr (sizes < xieite::types::sizeBits<Integer>) {
					item &= std::numeric_limits<xieite::types::MaybeUnsigned<Integer>>::max() >> (xieite::types::sizeBits<Integer> - sizes);
				}
				value >>= sizes;
				return item;
			})()...
		};
	}
}

#endif
