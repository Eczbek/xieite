#ifndef XIEITE_HEADER_BITS_MASH
#	define XIEITE_HEADER_BITS_MASH

#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include <utility>
#	include "../types/try_unsigned.hpp"

namespace xieite::bits {
	template<std::size_t... sizes_, std::integral... Integrals_>
	[[nodiscard]] constexpr std::bitset<(... + sizes_)> mash(const Integrals_... values) noexcept {
		std::bitset<(... + sizes_)> result;
		(..., (result = (result >> sizes_) | (std::bitset<(... + sizes_)>(static_cast<xieite::types::TryUnsigned<Integrals_>>(values)) << ((... + sizes_) - sizes_))));
		return result;
	}

	template<std::size_t... sizes_, std::integral Integral_>
	[[nodiscard]] constexpr std::bitset<(... + sizes_)> mash(const std::array<Integral_, sizeof...(sizes_)>& values) noexcept {
		return ([&values]<std::size_t... i_>(std::index_sequence<i_...>) {
			std::bitset<(... + sizes_)> result;
			(..., (result = (result >> sizes_) | (std::bitset<(... + sizes_)>(static_cast<xieite::types::TryUnsigned<Integral_>>(values[i_])) << ((... + sizes_) - sizes_))));
			return result;
		})(std::make_index_sequence<sizeof...(sizes_)>());
	}
}

#endif
