#ifndef DETAIL_XTE_HEADER_MATH_LOWERCASE
#	define DETAIL_XTE_HEADER_MATH_LOWERCASE
#
#	include "../data/string.hpp"
#	include "../data/string_view.hpp"
#	include "../trait/is_noex_range.hpp"
#	include "../trait/is_same.hpp"
#	include "../util/as.hpp"
#	include "../util/assign.hpp"
#	include "../util/make.hpp"
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

	template<std::ranges::input_range range_type>
	[[nodiscard]] constexpr range_type lowercase(range_type range)
	noexcept(xte::is_noex_range<range_type>
		&& requires (std::ranges::range_value_t<range_type> x) { { xte::assign(x, xte::lowercase(xte::make<char>(xte::as<range_type>(x)))) } noexcept; })
	requires(requires (std::ranges::range_value_t<range_type> x) { xte::assign(x, xte::lowercase(xte::make<char>(xte::as<range_type>(x)))); }) {
		for (auto& c : range) {
			xte::assign(c, xte::lowercase(xte::make<char>(xte::as<range_type>(c))));
		}
		return range;
	}
}

#endif
