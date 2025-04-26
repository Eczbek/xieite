#ifndef DETAIL_XIEITE_HEADER_MATH_MASH_BITS
#	define DETAIL_XIEITE_HEADER_MATH_MASH_BITS
#
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include "../fn/unroll.hpp"
#	include "../trait/try_unsigned.hpp"

namespace xieite {
	template<std::size_t... sizes, std::integral... Ints>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> mash_bits(Ints... args) noexcept {
		static constexpr std::size_t bits = (... + sizes);
		std::bitset<bits> result;
		(..., (result = (result >> sizes) | (std::bitset<bits>(static_cast<xieite::try_unsigned<Ints>>(args)) << (bits - sizes))));
		return result;
	}

	template<std::size_t... sizes, std::integral Int>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> mash_bits(const std::array<Int, sizeof...(sizes)>& args) noexcept {
		static constexpr std::size_t bits = (... + sizes);
		std::bitset<bits> result;
		xieite::unroll<sizeof...(sizes)>([&args, &result]<std::size_t... i> -> void {
			(..., (result = (result >> sizes) | (std::bitset<bits>(static_cast<xieite::try_unsigned<Int>>(args[i])) << (bits - sizes))));
		});
		return result;
	}
}

#endif
