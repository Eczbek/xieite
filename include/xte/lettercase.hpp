#ifndef DETAIL_XTE_HEADER_LOWERCASE
#	define DETAIL_XTE_HEADER_LOWERCASE
#
#	include "./assign.hpp"
#	include "./make.hpp"
#	include "./qual_traits.hpp"
#	include "./range_traits.hpp"
#	include "./string.hpp"
#	include "./string_view.hpp"
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

	[[nodiscard]] constexpr xte::string uppercase(xte::string_view string) noexcept(false) {
		auto result = xte::string(string);
		for (char& c : result) {
			c = xte::uppercase(c);
		}
		return result;
	}

	[[nodiscard]] constexpr xte::string lowercase(xte::string_view string) noexcept(false) {
		auto result = xte::string(string);
		for (char& c : result) {
			c = xte::lowercase(c);
		}
		return result;
	}

	template<std::ranges::input_range range_type>
	[[nodiscard]] constexpr range_type uppercase(range_type range)
	noexcept(xte::is_range_noex<range_type>
		&& requires (std::ranges::range_value_t<range_type> x) { { xte::assign(x, xte::uppercase(xte::make<char>(xte::like<range_type>(x)))) } noexcept; })
	requires(requires (std::ranges::range_value_t<range_type> x) { xte::assign(x, xte::uppercase(xte::make<char>(xte::like<range_type>(x)))); }) {
		for (auto& c : range) {
			xte::assign(c, xte::uppercase(xte::make<char>(xte::like<range_type>(c))));
		}
		return range;
	}

	template<std::ranges::input_range range_type>
	[[nodiscard]] constexpr range_type lowercase(range_type range)
	noexcept(xte::is_range_noex<range_type>
		&& requires (std::ranges::range_value_t<range_type> x) { { xte::assign(x, xte::lowercase(xte::make<char>(xte::like<range_type>(x)))) } noexcept; })
	requires(requires (std::ranges::range_value_t<range_type> x) { xte::assign(x, xte::lowercase(xte::make<char>(xte::like<range_type>(x)))); }) {
		for (auto& c : range) {
			xte::assign(c, xte::lowercase(xte::make<char>(xte::like<range_type>(c))));
		}
		return range;
	}
}

#endif
