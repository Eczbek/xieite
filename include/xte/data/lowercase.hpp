#ifndef DETAIL_XTE_HEADER_MATH_LOWERCASE
#	define DETAIL_XTE_HEADER_MATH_LOWERCASE
#
#	include "../func/visitor.hpp"
#	include "../trait/is_noex_range.hpp"
#	include "../trait/is_same.hpp"
#	include <ranges>

namespace DETAIL_XTE {
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
}

namespace xte {
	inline constexpr auto lowercase = xte::visitor {
		[][[nodiscard]](char c) static noexcept -> char {
			return DETAIL_XTE::lowercase(c);
		},
		[]<std::ranges::input_range Range>[[nodiscard]](Range range) static noexcept(xte::is_noex_range<Range>) -> Range requires(xte::is_same<std::ranges::range_value_t<Range>, char>) {
			for (char& c : range) {
				c = DETAIL_XTE::lowercase(c);
			}
			return range;
		}
	};
}

#endif
