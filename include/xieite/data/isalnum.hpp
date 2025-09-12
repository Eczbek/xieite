#ifndef DETAIL_XIEITE_HEADER_DATA_ISALNUM
#	define DETAIL_XIEITE_HEADER_DATA_ISALNUM
#
#	include <string>
#	include <string_view>
#	include "../data/isalpha.hpp"
#	include "../data/isdigit.hpp"
#	include "../data/make_str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool isalnum(xieite::is_char auto c) noexcept {
		return xieite::isalpha(c) || xieite::isdigit(c);
	}

	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr bool isalnum(std::basic_string_view<Char, Traits> strv) noexcept {
		for (Char c : strv) {
			if (!xieite::isalnum(c)) {
				return false;
			}
		}
		return true;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr auto isalnum(const std::basic_string<Char, Traits, Alloc>& str)
		XIEITE_ARROW(xieite::isalnum(xieite::make_str_view(str)))

	template<xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr auto isalnum(const xieite::paren<Char[length]>& str)
		XIEITE_ARROW(xieite::isalnum(xieite::make_str_view(str)))
}

#endif
