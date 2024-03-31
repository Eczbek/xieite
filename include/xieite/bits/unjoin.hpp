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
	template<std::integral... Integrals>
	[[nodiscard]] constexpr std::tuple<Integrals...> unjoin(std::bitset<(... + xieite::types::sizeBits<Integrals>)> value) noexcept {
		return xieite::containers::reverseTuple(std::make_tuple<Integrals...>(([&value] {
			const Integrals item = static_cast<Integrals>(value.to_ullong());
			value >>= xieite::types::sizeBits<Integrals>;
			return item;
		})()...));
	}

	template<std::integral Integral, std::size_t size>
	[[nodiscard]] constexpr std::array<Integral, size> unjoin(std::bitset<xieite::types::sizeBits<Integral> * size> value) noexcept {
		std::array<Integral, size> result;
		for (std::size_t i = 0; i < size; ++i) {
			result[i] = static_cast<Integral>(value.to_ullong());
			value >>= xieite::types::sizeBits<Integral>;
		}
		return result;
	}
}

#endif
