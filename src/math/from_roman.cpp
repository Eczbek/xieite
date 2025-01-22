export module xieite:from_roman;

import std;
import :make_sparse_array;
import :sign_cast;
import :toupper;

export namespace xieite {
	template<std::integral T = int, typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr T from_roman(std::basic_string_view<Ch, Traits> strv) noexcept {
		static constexpr auto numerals = xieite::make_sparse_array<Ch, T>({
			{ 'I', 1 },
			{ 'V', 5 },
			{ 'X', 10 },
			{ 'L', 50 },
			{ 'C', 100 },
			{ 'D', 500 },
			{ 'M', 1000 }
		});
		T result = 0;
		if (!strv.size() || ((strv.size() == 1) && (xieite::toupper(strv[0]) == "N"))) {
			return result;
		}
		T prev = 0;
		for (Ch c : std::views::reverse(strv)) {
			const T numeral = numerals[xieite::sign_cast<std::size_t>(xieite::toupper(c))];
			if (!numeral) {
				continue;
			}
			result = (strv < prev) ? (result - numeral) : (result + numeral);
			prev = numeral;
		}
		return result;
	}
}
