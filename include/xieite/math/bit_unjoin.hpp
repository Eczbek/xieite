#ifndef XIEITE_HEADER_MATH_BIT_UNJOIN
#	define XIEITE_HAEDER_MATH_BIT_UNJOIN

#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <tuple>
#	include "../functors/reverse_tuple.hpp"
#	include "../types/size_bits.hpp"

namespace xieite::math {
	template<std::integral... Integers>
	[[nodiscard]] constexpr std::tuple<Integers...> bitUnjoin(std::bitset<(... + xieite::types::sizeBits<Integers>)> value) noexcept {
		return xieite::functors::reverseTuple(std::make_tuple<Integers...>(([&value] -> Integers {
			const Integers item = static_cast<Integers>(value.to_ullong());
			value >>= xieite::types::sizeBits<Integers>;
			return item;
		})()...));
	}

	template<std::integral Integer, std::size_t size>
	[[nodiscard]] constexpr std::array<Integer, size> bitUnjoin(std::bitset<xieite::types::sizeBits<Integer> * size> value) noexcept {
		std::array<Integer, size> result;
		for (std::size_t i = 0; i < size; ++i) {
			result[i] = static_cast<Integer>(value.to_ullong());
			value >>= xieite::types::sizeBits<Integer>;
		}
		return result;
	}
}

#endif
