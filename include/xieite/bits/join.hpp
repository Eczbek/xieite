#ifndef XIEITE_HEADER_BITS_JOIN
#	define XIEITE_HEADER_BITS_JOIN

#	include <array>
#	include <bitset>
#	include <concepts>
#	include <cstddef>
#	include "../bits/size.hpp"
#	include "../types/try_unsigned.hpp"

namespace xieite::bits {
	template<std::integral... Integrals_>
	[[nodiscard]] constexpr std::bitset<(... + xieite::bits::size<Integrals_>)> join(const Integrals_... values) noexcept {
		std::bitset<(... + xieite::bits::size<Integrals_>)> result;
		(..., (result = (result >> xieite::bits::size<Integrals_>) | (std::bitset<(... + xieite::bits::size<Integrals_>)>(static_cast<xieite::types::TryUnsigned<Integrals_>>(values)) << ((... + xieite::bits::size<Integrals_>) - xieite::bits::size<Integrals_>))));
		return result;
	}

	template<std::integral Integral_, std::size_t size_>
	[[nodiscard]] constexpr std::bitset<xieite::bits::size<Integral_> * size_> join(const std::array<Integral_, size_>& values) noexcept {
		std::bitset<xieite::bits::size<Integral_> * size_> result;
		for (const Integral_ value : values) {
			result = (result >> xieite::bits::size<Integral_>) | (std::bitset<xieite::bits::size<Integral_> * size_>(static_cast<xieite::types::TryUnsigned<Integral_>>(value)) << (xieite::bits::size<Integral_> * (size_ - 1)));
		}
		return result;
	}
}

#endif
