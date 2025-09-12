#ifndef DETAIL_XIEITE_HEADER_DATA_TOUPPER
#	define DETAIL_XIEITE_HEADER_DATA_TOUPPER
#
#	include <cstddef>
#	include <memory>
#	include <string>
#	include <string_view>
#	include "../data/make_str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char>
	[[nodiscard]] constexpr Char toupper(Char c) noexcept {
		switch (c) {
		case 'a': return 'A';
		case 'b': return 'B';
		case 'c': return 'C';
		case 'd': return 'D';
		case 'e': return 'E';
		case 'f': return 'F';
		case 'g': return 'G';
		case 'h': return 'H';
		case 'i': return 'I';
		case 'j': return 'J';
		case 'k': return 'K';
		case 'l': return 'L';
		case 'm': return 'M';
		case 'n': return 'N';
		case 'o': return 'O';
		case 'p': return 'P';
		case 'q': return 'Q';
		case 'r': return 'R';
		case 's': return 'S';
		case 't': return 'T';
		case 'u': return 'U';
		case 'v': return 'V';
		case 'w': return 'W';
		case 'x': return 'X';
		case 'y': return 'Y';
		case 'z': return 'Z';
		}
		return c;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> toupper(std::basic_string_view<Char, Traits> strv, const Alloc& alloc = {}) noexcept(false) {
		auto result = std::basic_string<Char, Traits, Alloc>(strv, alloc);
		for (Char& c : result) {
			c = xieite::toupper(c);
		}
		return result;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> toupper(const std::basic_string<Char, Traits, Alloc>& str, const Alloc& alloc = {}) noexcept(false) {
		return xieite::toupper(xieite::make_str_view(str), alloc);
	}

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>, std::size_t length>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> toupper(const xieite::paren<Char[length]>& str, const Alloc& alloc = {}) noexcept(false) {
		return xieite::toupper(xieite::make_str_view<Char, Traits>(str), alloc);
	}
}

#endif
