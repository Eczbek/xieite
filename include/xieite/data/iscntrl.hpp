#ifndef DETAIL_XIEITE_HEADER_DATA_ISCNTRL
#	define DETAIL_XIEITE_HEADER_DATA_ISCNTRL
#
#	include <string>
#	include <string_view>
#	include "../data/isprint.hpp"
#	include "../data/str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool iscntrl(xieite::is_char auto c) noexcept {
		return !xieite::isprint(c);
	}

	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr bool iscntrl(std::basic_string_view<Char, Traits> strv) noexcept {
		for (Char c : strv) {
			if (!xieite::iscntrl(c)) {
				return false;
			}
		}
		return true;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr auto iscntrl(const std::basic_string<Char, Traits, Alloc>& str)
		XIEITE_ARROW(xieite::iscntrl(xieite::str_view(str)))

	template<xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr auto iscntrl(const xieite::paren<Char[length]>& str)
		XIEITE_ARROW(xieite::iscntrl(xieite::str_view(str)))
}

#endif
