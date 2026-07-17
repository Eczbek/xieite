#ifndef DETAIL_XTE_HEADER_MATH_UPPERCASE
#	define DETAIL_XTE_HEADER_MATH_UPPERCASE
#
#	include "../data/string.hpp"
#	include "../data/string_view.hpp"
#	include "../trait/is_noex_range.hpp"
#	include "../trait/is_same.hpp"
#	include "../util/assign.hpp"
#	include "../util/as.hpp"
#	include "../util/make.hpp"
#	include <ranges>

namespace xte {
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

	[[nodiscard]] constexpr xte::string uppercase(xte::string_view string) noexcept(false) {
		auto result = xte::string(string);
		for (char& c : result) {
			c = xte::uppercase(c);
		}
		return result;
	}

	template<std::ranges::input_range Range>
	[[nodiscard]] constexpr Range uppercase(Range range)
	noexcept(xte::is_noex_range<Range>
		&& requires (std::ranges::range_value_t<Range> x) { { xte::assign(x, xte::uppercase(xte::make<char>(xte::as<Range>(x)))) } noexcept; })
	requires(requires (std::ranges::range_value_t<Range> x) { xte::assign(x, xte::uppercase(xte::make<char>(xte::as<Range>(x)))); }) {
		for (auto& c : range) {
			xte::assign(c, xte::uppercase(xte::make<char>(xte::as<Range>(c))));
		}
		return range;
	}
}

#endif
