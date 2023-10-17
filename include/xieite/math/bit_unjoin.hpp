#ifndef XIEITE_HEADER_MATH_BIT_UNJOIN
#	define XIEITE_HAEDER_MATH_BIT_UNJOIN

#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <tuple>
#	include <utility>
#	include "../types/size_bits.hpp"

namespace xieite::math {
	template<std::integral... Integers>
	[[nodiscard]] constexpr std::tuple<Integers...> bitUnjoin(const std::bitset<(... + xieite::types::sizeBits<Integers>)>& bits) noexcept {
		std::tuple<Integers...> result;
		std::size_t shift = (... + xieite::types::sizeBits<Integers>);
		([&bits, &result, &shift]<std::size_t... indices>(std::index_sequence<indices...>) {
			(..., (std::get<indices>(result) = static_cast<Integers>((bits >> (shift -= xieite::types::sizeBits<Integers>)).to_ullong())));
		})(std::make_index_sequence<sizeof...(Integers)>());
		return result;
	}
}

#endif
