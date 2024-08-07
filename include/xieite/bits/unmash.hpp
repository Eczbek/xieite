#ifndef XIEITE_HEADER_BITS_UNMASH
#	define XIEITE_HAEDER_BITS_UNMASH

#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <limits>
#	include <tuple>
#	include "../bits/size.hpp"
#	include "../containers/reverse_tuple.hpp"
#	include "../types/least_integer.hpp"
#	include "../types/try_unsigned.hpp"

namespace xieite::bits {
	template<std::size_t... sizes_, std::size_t bits_>
	requires(bits_ >= (... + sizes_))
	[[nodiscard]] constexpr std::tuple<xieite::types::LeastInteger<sizes_>...> unmash(std::bitset<bits_> value) noexcept {
		return xieite::containers::reverseTuple(std::make_tuple<xieite::types::LeastInteger<sizes_>...>(([&value] {
			using Integral = xieite::types::LeastInteger<sizes_>;
			Integral item = static_cast<Integral>(value.to_ullong());
			if constexpr (sizes_ < xieite::bits::size<Integral>) {
				item &= std::numeric_limits<Integral>::max() >> (xieite::bits::size<Integral> - sizes_);
			}
			value >>= sizes_;
			return item;
		})()...));
	}

	template<std::integral Integral_, std::size_t... sizes_, std::size_t bits_>
	requires(bits_ >= (... + sizes_))
	[[nodiscard]] constexpr std::array<Integral_, sizeof...(sizes_)> unmash(std::bitset<bits_> value) noexcept {
		return std::array<Integral_, sizeof...(sizes_)> {
			([&value] {
				Integral_ item = static_cast<Integral_>(value.to_ullong());
				if constexpr (sizes_ < xieite::bits::size<Integral_>) {
					item &= std::numeric_limits<xieite::types::TryUnsigned<Integral_>>::max() >> (xieite::bits::size<Integral_> - sizes_);
				}
				value >>= sizes_;
				return item;
			})()...
		};
	}
}

#endif
