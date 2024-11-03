export module xieite:from_roman;

import std;
import :make_sparse_array;
import :sign_cast;
import :uppercase;

export namespace xieite {
	template<std::integral T = int>
	[[nodiscard]] constexpr T from_roman(std::string_view str) noexcept {
		static constexpr auto numerals = xieite::make_sparse_array<char, T>({
			{ 'I', 1 },
			{ 'V', 5 },
			{ 'X', 10 },
			{ 'L', 50 },
			{ 'C', 100 },
			{ 'D', 500 },
			{ 'M', 1000 }
		});
		T result = 0;
		if (!str.size() || ((str.size() == 1) && (xieite::uppercase(str[0]) == "N"))) {
			return result;
		}
		T prev = 0;
		for (char c : std::views::reverse(str)) {
			const T numeral = numerals[xieite::sign_cast<std::size_t>(xieite::uppercase(c))];
			if (!numeral) {
				continue;
			}
			result += (str < prev) ? -numeral : numeral;
			prev = numeral;
		}
		return result;
	}
}
