#ifndef DETAIL_XIEITE_HEADER_DATA_ISDIGIT
#	define DETAIL_XIEITE_HEADER_DATA_ISDIGIT
#
#	include <string>
#	include <string_view>
#	include "../data/str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool isdigit(xieite::is_char auto c) noexcept {
		return (c >= '0') && (c <= '9');
	}

	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr bool isdigit(std::basic_string_view<Char, Traits> strv) noexcept {
		for (Char c : strv) {
			if (!xieite::isdigit(c)) {
				return false;
			}
		}
		return true;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr auto isdigit(const std::basic_string<Char, Traits, Alloc>& str)
		XIEITE_ARROW(xieite::isdigit(xieite::str_view(str)))

	template<xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr auto isdigit(const xieite::paren<Char[length]>& str)
		XIEITE_ARROW(xieite::isdigit(xieite::str_view(str)))
}

#endif

// https://timsong-cpp.github.io/cppwp/n4950/lex.charset#9.sentence-5
