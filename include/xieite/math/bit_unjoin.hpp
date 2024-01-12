#ifndef XIEITE_HEADER_MATH_BIT_UNJOIN
#	define XIEITE_HAEDER_MATH_BIT_UNJOIN

#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <tuple>
#	include <utility>
#	include "../types/size_bits.hpp"

namespace xieite::math {
	template<std::integral... Integers>
	[[nodiscard]] constexpr std::tuple<Integers...> bitUnjoin(const std::bitset<(... + xieite::types::sizeBits<Integers>)>& value) noexcept {
		std::tuple<Integers...> result;
		std::size_t shift = (... + xieite::types::sizeBits<Integers>);
		([&value, &result, &shift]<std::size_t... indices>(std::index_sequence<indices...>) {
			(..., (std::get<indices>(result) = static_cast<Integers>((value >> (shift -= xieite::types::sizeBits<Integers>)).to_ullong())));
		})(std::make_index_sequence<sizeof...(Integers)>());
		return result;
	}

	template<std::integral Integer, std::size_t size>
	[[nodiscard]] constexpr std::array<Integer, size> bitUnjoin(const std::bitset<xieite::types::sizeBits<Integer> * size>& value) noexcept {
		static constexpr std::size_t bits = xieite::types::sizeBits<Integer> * size;
		std::array<Integer, size> result;
		std::size_t shift = bits;
		for (std::size_t i = 0; i < size; ++i) {
			shift -= xieite::types::sizeBits<Integer>;
			result[i] = static_cast<Integer>((value >> shift).to_ullong());
		}
		return result;
	}
}

#endif
