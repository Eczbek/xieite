#ifndef XIEITE_HEADER_BITS_UNJOIN
#	define XIEITE_HAEDER_BITS_UNJOIN

#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <tuple>
#	include "../containers/reverse_tuple.hpp"
#	include "../types/size_bits.hpp"

namespace xieite::bits {
	template<std::integral... Integrals_>
	[[nodiscard]] constexpr std::tuple<Integrals_...> unjoin(std::bitset<(... + xieite::types::sizeBits<Integrals_>)> value) noexcept {
		return xieite::containers::reverseTuple(std::make_tuple<Integrals_...>(([&value] {
			const Integrals_ item = static_cast<Integrals_>(value.to_ullong());
			value >>= xieite::types::sizeBits<Integrals_>;
			return item;
		})()...));
	}

	template<std::integral Integral_, std::size_t size_>
	[[nodiscard]] constexpr std::array<Integral_, size_> unjoin(std::bitset<xieite::types::sizeBits<Integral_> * size_> value) noexcept {
		std::array<Integral_, size_> result;
		for (std::size_t i = 0; i < size_; ++i) {
			result[i] = static_cast<Integral_>(value.to_ullong());
			value >>= xieite::types::sizeBits<Integral_>;
		}
		return result;
	}
}

#endif
