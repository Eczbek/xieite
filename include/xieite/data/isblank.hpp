#ifndef DETAIL_XIEITE_HEADER_DATA_ISBLANK
#	define DETAIL_XIEITE_HEADER_DATA_ISBLANK
#
#	include <string>
#	include <string_view>
#	include "../data/str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool isblank(xieite::is_char auto c) noexcept {
		return (c == ' ') || (c == '\t');
	}

	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr bool isblank(std::basic_string_view<Char, Traits> strv) noexcept {
		for (Char c : strv) {
			if (!xieite::isblank(c)) {
				return false;
			}
		}
		return true;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr auto isblank(const std::basic_string<Char, Traits, Alloc>& str)
		XIEITE_ARROW(xieite::isblank(xieite::str_view(str)))

	template<xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr auto isblank(const xieite::paren<Char[length]>& str)
		XIEITE_ARROW(xieite::isblank(xieite::str_view(str)))
}

#endif
