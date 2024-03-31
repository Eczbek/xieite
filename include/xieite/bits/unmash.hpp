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
		return xieite::containers::reverseTuple(std::make_tuple<xieite::types::LeastInteger<sizes>...>(([&value] {
			using Integral = xieite::types::LeastInteger<sizes>;
			Integral item = static_cast<Integral>(value.to_ullong());
			if constexpr (sizes < xieite::types::sizeBits<Integral>) {
				item &= std::numeric_limits<Integral>::max() >> (xieite::types::sizeBits<Integral> - sizes);
			}
			value >>= sizes;
			return item;
		})()...));
	}

	template<std::integral Integral, std::size_t... sizes>
	[[nodiscard]] constexpr std::array<Integral, sizeof...(sizes)> unmash(std::bitset<(... + sizes)> value) noexcept {
		return std::array<Integral, sizeof...(sizes)> {
			([&value] {
				Integral item = static_cast<Integral>(value.to_ullong());
				if constexpr (sizes < xieite::types::sizeBits<Integral>) {
					item &= std::numeric_limits<xieite::types::MaybeUnsigned<Integral>>::max() >> (xieite::types::sizeBits<Integral> - sizes);
				}
				value >>= sizes;
				return item;
			})()...
		};
	}
}

#endif
