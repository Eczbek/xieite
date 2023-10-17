#ifndef XIEITE_HEADER_STRINGS_TO_ROMAN_NUMERALS
#	define XIEITE_HEADER_STRINGS_TO_ROMAN_NUMERALS

#	include <array>
#	include <concepts>
#	include <string>
#	include <string_view>
#	include "../math/absolute.hpp"
#	include "../types/maybe_unsigned.hpp"

namespace xieite::strings {
	template<std::integral Integer>
	[[nodiscard]] constexpr std::string toRomanNumerals(const Integer value) noexcept {
		static constexpr std::array<std::string_view, 10> units {
			"",
			"I",
			"II",
			"III",
			"IV",
			"V",
			"VI",
			"VII",
			"VIII",
			"IX"
		};
		static constexpr std::array<std::string_view, 10> tens {
			"",
			"X",
			"XX",
			"XXX",
			"XL",
			"L",
			"LX",
			"LXX",
			"LXXX",
			"XC"
		};
		static constexpr std::array<std::string_view, 10> hundreds {
			"",
			"C",
			"CC",
			"CCC",
			"CD",
			"D",
			"DC",
			"DCC",
			"DCCC",
			"CM"
		};
		const xieite::types::MaybeUnsigned<Integer> absoluteValue = xieite::math::absolute(value);
		return absoluteValue ? (std::string(absoluteValue / 1000, 'M') + std::string(hundreds[absoluteValue / 100 % 10]) + std::string(tens[absoluteValue / 10 % 10]) + std::string(units[absoluteValue % 10])) : "N";
	}
}

#endif
