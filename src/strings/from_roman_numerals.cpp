export module xieite:strings.fromRomanNumerals;

import std;
import :containers.makeSparseArray;
import :strings.uppercase;

export namespace xieite::strings {
	template<std::integral Integral = int>
	[[nodiscard]] constexpr Integral fromRomanNumerals(const std::string_view value) noexcept {
		static constexpr auto numerals = xieite::containers::makeSparseArray<char, Integral>({
			{ 'I', 1 },
			{ 'V', 5 },
			{ 'X', 10 },
			{ 'L', 50 },
			{ 'C', 100 },
			{ 'D', 500 },
			{ 'M', 1000 }
		});
		Integral result = 0;
		if (!value.size() || ((value.size() == 1) && (xieite::strings::uppercase(value[0]) == "N"))) {
			return result;
		}
		Integral previous = 0;
		for (const char digit : std::views::reverse(value)) {
			const Integral value = numerals[xieite::strings::uppercase(digit)];
			if (!value) {
				continue;
			}
			result += (value < previous) ? -value : value;
			previous = value;
		}
		return result;
	}
}
