#ifndef XIEITE_HEADER_STRINGS_TO_ROMAN_NUMERALS
#	define XIEITE_HEADER_STRINGS_TO_ROMAN_NUMERALS

#	include <array>
#	include <concepts>
#	include <string>
#	include <string_view>
#	include "../concepts/string.hpp"
#	include "../math/absolute.hpp"
#	include "../strings/view.hpp"
#	include "../types/maybe_unsigned.hpp"

namespace xieite::strings {
	template<std::integral Integer, xieite::strings::String String = std::string>
	[[nodiscard]] constexpr String toRomanNumerals(const Integer value) noexcept {
		static constexpr std::array<xieite::strings::View<String>, 10> units {
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
		static constexpr std::array<xieite::strings::View<String>, 10> tens {
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
		static constexpr std::array<xieite::strings::View<String>, 10> hundreds {
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
		if (!value) {
			return "N";
		}
		const xieite::types::MaybeUnsigned<Integer> absoluteValue = xieite::math::absolute(value);
		return String(absoluteValue / 1000, 'M') + String(hundreds[absoluteValue / 100 % 10]) + String(tens[absoluteValue / 10 % 10]) + String(units[absoluteValue % 10]);
	}
}

#endif
