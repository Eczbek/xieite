export module xieite:from_roman;

import std;
import :make_sparse_array;
import :sign_cast;
import :uppercase;

export namespace xieite {
	template<std::integral T = int, typename C = char, typename Traits = std::char_traits<C>>
	[[nodiscard]] constexpr T from_roman(std::basic_string_view<C, Traits> str) noexcept {
		static constexpr auto numerals = xieite::make_sparse_array<C, T>({
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
		for (C c : std::views::reverse(str)) {
			const T numeral = numerals[xieite::sign_cast<std::size_t>(xieite::uppercase(c))];
			if (!numeral) {
				continue;
			}
			result = (str < prev) ? (result - numeral) : (result + numeral);
			prev = numeral;
		}
		return result;
	}
}
