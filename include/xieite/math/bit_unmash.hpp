#ifndef XIEITE_HEADER_MATH_BIT_UNMASH
#	define XIEITE_HAEDER_MATH_BIT_UNMASH

#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <string>
#	include <tuple>
#	include <utility>
#	include "../types/least_integer.hpp"

namespace xieite::math {
	template<std::size_t... sizes>
	[[nodiscard]] constexpr std::tuple<xieite::types::LeastInteger<sizes>...> bitUnmash(const std::bitset<(... + sizes)>& value) noexcept {
		static constexpr std::size_t bits = (... + sizes);
		std::tuple<xieite::types::LeastInteger<sizes>...> result;
		std::size_t shift = bits;
		([&bits, &value, &result, &shift]<std::size_t... indices>(std::index_sequence<indices...>) {
			(..., (std::get<indices>(result) = static_cast<xieite::types::LeastInteger<sizes>>(((value >> (shift -= sizes)) & std::bitset<bits>(std::string(sizes, '1'))).to_ullong())));
		})(std::make_index_sequence<sizeof...(sizes)>());
		return result;
	}

	template<std::integral Integer, std::size_t... sizes>
	[[nodiscard]] constexpr std::array<Integer, sizeof...(sizes)> bitUnmash(const std::bitset<(... + sizes)>& value) noexcept {
		static constexpr std::size_t bits = (... + sizes);
		std::array<Integer, sizeof...(sizes)> result;
		std::size_t shift = bits;
		std::size_t i = 0;
		(..., (result[i++] = static_cast<Integer>(((value >> (shift -= sizes)) & std::bitset<bits>(std::string(sizes, '1'))).to_ullong())));
		return result;
	}
}

#endif
