#ifndef DETAIL_XTE_HEADER_MATH_UPPERCASE
#	define DETAIL_XTE_HEADER_MATH_UPPERCASE
#
#	include "../func/visitor.hpp"
#	include "../trait/is_noex_range.hpp"
#	include "../trait/is_same.hpp"
#	include <ranges>

namespace DETAIL_XTE {
	[[nodiscard]] constexpr char uppercase(char c) noexcept {
		switch (c) {
			case 'a':
				return 'A';
			case 'b':
				return 'B';
			case 'c':
				return 'C';
			case 'd':
				return 'D';
			case 'e':
				return 'E';
			case 'f':
				return 'F';
			case 'g':
				return 'G';
			case 'h':
				return 'H';
			case 'i':
				return 'I';
			case 'j':
				return 'J';
			case 'k':
				return 'K';
			case 'l':
				return 'L';
			case 'm':
				return 'M';
			case 'n':
				return 'N';
			case 'o':
				return 'O';
			case 'p':
				return 'P';
			case 'q':
				return 'Q';
			case 'r':
				return 'R';
			case 's':
				return 'S';
			case 't':
				return 'T';
			case 'u':
				return 'U';
			case 'v':
				return 'V';
			case 'w':
				return 'W';
			case 'x':
				return 'X';
			case 'y':
				return 'Y';
			case 'z':
				return 'Z';
		}
		return c;
	}
}

namespace xte {
	inline constexpr auto uppercase = xte::visitor {
		[][[nodiscard]](char c) static noexcept -> char {
			return DETAIL_XTE::uppercase(c);
		},
		[]<std::ranges::input_range Range>[[nodiscard]](Range range) static noexcept(xte::is_noex_range<Range>) -> Range requires(xte::is_same<std::ranges::range_value_t<Range>, char>) {
			for (char& c : range) {
				c = DETAIL_XTE::uppercase(c);
			}
			return range;
		}
	};
}

#endif
