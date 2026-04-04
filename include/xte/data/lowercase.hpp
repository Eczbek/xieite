#ifndef DETAIL_XTE_HEADER_MATH_LOWERCASE
#	define DETAIL_XTE_HEADER_MATH_LOWERCASE
#
#	include "../data/string.hpp"
#	include "../data/string_view.hpp"
#	include "../trait/is_noex_range.hpp"
#	include "../trait/is_same.hpp"
#	include <ranges>

namespace xte {
	[[nodiscard]] constexpr char lowercase(char c) noexcept {
		switch (c) {
			case 'A':
				return 'a';
			case 'B':
				return 'b';
			case 'C':
				return 'c';
			case 'D':
				return 'd';
			case 'E':
				return 'e';
			case 'F':
				return 'f';
			case 'G':
				return 'g';
			case 'H':
				return 'h';
			case 'I':
				return 'i';
			case 'J':
				return 'j';
			case 'K':
				return 'k';
			case 'L':
				return 'l';
			case 'M':
				return 'm';
			case 'N':
				return 'n';
			case 'O':
				return 'o';
			case 'P':
				return 'p';
			case 'Q':
				return 'q';
			case 'R':
				return 'r';
			case 'S':
				return 's';
			case 'T':
				return 't';
			case 'U':
				return 'u';
			case 'V':
				return 'v';
			case 'W':
				return 'w';
			case 'X':
				return 'x';
			case 'Y':
				return 'y';
			case 'Z':
				return 'z';
		}
		return c;
	}

	[[nodiscard]] constexpr xte::string lowercase(xte::string_view string) noexcept(false) {
		auto result = xte::string(string);
		for (char& c : result) {
			c = xte::lowercase(c);
		}
		return result;
	}

	template<std::ranges::input_range Range>
	[[nodiscard]] constexpr Range lowercase(Range range)
	noexcept(xte::is_noex_range<Range> && requires (std::ranges::range_value_t<Range> x) { requires(noexcept(x = xte::lowercase(static_cast<char>(x)))); })
	requires(requires (std::ranges::range_value_t<Range> x) { x = xte::lowercase(static_cast<char>(x)); }) {
		for (char& c : range) {
			c = xte::lowercase(static_cast<char>(c));
		}
		return range;
	}
}

#endif
