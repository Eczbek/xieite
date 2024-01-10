#ifndef XIEITE_HEADER_MATH_BIT_UNMASH
#	define XIEITE_HAEDER_MATH_BIT_UNMASH

#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <string>
#	include <tuple>
#	include <utility>
#	include "../math/least_integer.hpp"

namespace xieite::math {
	template<std::size_t... sizes>
	[[nodiscard]] constexpr std::tuple<xieite::math::LeastInteger<sizes>...> bitUnmash(const std::bitset<(... + sizes)>& bits) noexcept {
		std::tuple<xieite::math::LeastInteger<sizes>...> result;
		std::size_t shift = (... + sizes);
		([&bits, &result, &shift]<std::size_t... indices>(std::index_sequence<indices...>) {
			(..., (std::get<indices>(result) = static_cast<xieite::math::LeastInteger<sizes>>(((bits >> (shift -= sizes)) & std::bitset<(... + sizes)>(std::string(sizes, '1'))).to_ullong())));
		})(std::make_index_sequence<sizeof...(sizes)>());
		return result;
	}
}

#endif
