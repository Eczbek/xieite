#ifndef XIEITE_HEADER_MATH_BIT_MASH
#	define XIEITE_HEADER_MATH_BIT_MASH

#	include <bitset>
#	include <concepts>
#	include <cstddef>

namespace xieite::math {
	template<std::size_t... sizes, std::integral... Integers>
	[[nodiscard]] constexpr std::bitset<(... + sizes)> bitMash(const Integers... values) noexcept {
		std::bitset<(... + sizes)> result;
		std::size_t shift = (... + sizes);
		(..., (result |= std::bitset<(... + sizes)>(static_cast<unsigned long long int>(values)) << (shift -= sizes)));
		return result;
	}
}

#endif