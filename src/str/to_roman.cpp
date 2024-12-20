export module xieite:to_roman;

import std;
import :abs;

export namespace xieite {
	template<std::integral T, typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> to_roman(T value) noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		using Array = std::array<std::basic_string_view<Ch, Traits>, 10>;
		static constexpr Array ones = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
		static constexpr Array tens = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
		static constexpr Array hundreds = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
		if (!value) {
			return "N";
		}
		const auto abs = xieite::abs(value);
		return Str(abs / 1000, 'M') + Str(hundreds[abs % 1000 / 100]) + Str(tens[abs % 100 / 10]) + Str(ones[abs % 10]);
	}
}
