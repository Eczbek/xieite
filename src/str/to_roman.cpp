export module xieite:to_roman;

import std;
import :abs;
import :chv;
import :end;

export namespace xieite {
	template<std::integral T, typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, xieite::end...,
		typename Str = std::basic_string<Ch, Traits, Alloc>>
	[[nodiscard]] constexpr Str to_roman(T value) noexcept {
		using Array = std::array<xieite::chv<Ch, Traits>, 10>;
		static constexpr Array ones = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
		static constexpr Array tens = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
		static constexpr Array hundreds = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
		if (!value) {
			return "N";
		}
		const auto abs = xieite::abs(value);
		return Str(abs / 1000, 'M') + hundreds[abs % 1000 / 100] + tens[abs % 100 / 10] + ones[abs % 10];
	}
}
