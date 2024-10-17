export module xieite:strings.toRomanNumerals;

import std;
import :math.absolute;

export namespace xieite::strings {
	template<std::integral Integral>
	[[nodiscard]] constexpr std::string toRomanNumerals(const Integral value) noexcept {
		static constexpr std::array<std::string_view, 10> ones = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
		static constexpr std::array<std::string_view, 10> tens = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
		static constexpr std::array<std::string_view, 10> hundreds = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
		if (!value) {
			return "N";
		}
		const auto absolute = xieite::math::absolute(value);
		return std::string(absolute / 1000, 'M') + std::string(hundreds[absolute / 100 % 10]) + std::string(tens[absolute / 10 % 10]) + std::string(ones[absolute % 10]);
	}
}
