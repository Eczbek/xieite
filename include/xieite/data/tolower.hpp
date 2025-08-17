#ifndef DETAIL_XIEITE_HEADER_DATA_TOLOWER
#	define DETAIL_XIEITE_HEADER_DATA_TOLOWER
#
#	include <cstddef>
#	include <memory>
#	include <string>
#	include <string_view>
#	include "../data/str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char>
	[[nodiscard]] constexpr Char tolower(Char c) noexcept {
		switch (c) {
		case 'A': return 'a';
		case 'B': return 'b';
		case 'C': return 'c';
		case 'D': return 'd';
		case 'E': return 'e';
		case 'F': return 'f';
		case 'G': return 'g';
		case 'H': return 'h';
		case 'I': return 'i';
		case 'J': return 'j';
		case 'K': return 'k';
		case 'L': return 'l';
		case 'M': return 'm';
		case 'N': return 'n';
		case 'O': return 'o';
		case 'P': return 'p';
		case 'Q': return 'q';
		case 'R': return 'r';
		case 'S': return 's';
		case 'T': return 't';
		case 'U': return 'u';
		case 'V': return 'v';
		case 'W': return 'w';
		case 'X': return 'x';
		case 'Y': return 'y';
		case 'Z': return 'z';
		}
		return c;
	}

	template<typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> tolower(std::basic_string_view<Char, Traits> strv, const Alloc& alloc = {}) noexcept(false) {
		auto result = std::basic_string<Char, Traits, Alloc>(strv, alloc);
		for (Char& c : result) {
			c = xieite::tolower(c);
		}
		return result;
	}

	template<typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr auto tolower(const std::basic_string<Char, Traits, Alloc>& str, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::tolower(xieite::str_view(str), alloc))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>, std::size_t length>
	[[nodiscard]] constexpr auto tolower(const xieite::paren<Char[length]>& str, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::tolower(xieite::str_view<Char, Traits>(str), alloc))
}

#endif
