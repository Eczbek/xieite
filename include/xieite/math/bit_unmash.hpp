#ifndef XIEITE_HEADER_MATH_BIT_UNMASH
#	define XIEITE_HAEDER_MATH_BIT_UNMASH

#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <limits>
#	include <tuple>
#	include "../functors/reverse_tuple.hpp"
#	include "../types/least_integer.hpp"
#	include "../types/maybe_unsigned.hpp"

namespace xieite::math {
	template<std::size_t... sizes>
	[[nodiscard]] constexpr std::tuple<xieite::types::LeastInteger<sizes>...> bitUnmash(std::bitset<(... + sizes)> value) noexcept {
		return xieite::functors::reverseTuple(std::make_tuple<xieite::types::LeastInteger<sizes>...>(([&value] -> xieite::types::LeastInteger<sizes> {
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
	[[nodiscard]] constexpr std::array<Integer, sizeof...(sizes)> bitUnmash(std::bitset<(... + sizes)> value) noexcept {
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
