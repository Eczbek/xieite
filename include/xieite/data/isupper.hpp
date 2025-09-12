#ifndef DETAIL_XIEITE_HEADER_DATA_ISUPPER
#	define DETAIL_XIEITE_HEADER_DATA_ISUPPER
#
#	include <string>
#	include <string_view>
#	include "../data/make_str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/cases.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool isupper(xieite::is_char auto c) noexcept {
		switch (c) {
		XIEITE_CASES('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'):
			return true;
		}
		return false;
	}

	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr bool isupper(std::basic_string_view<Char, Traits> strv) noexcept {
		for (Char c : strv) {
			if (!xieite::isupper(c)) {
				return false;
			}
		}
		return true;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr auto isupper(const std::basic_string<Char, Traits, Alloc>& str)
		XIEITE_ARROW(xieite::isupper(xieite::make_str_view(str)))

	template<xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr auto isupper(const xieite::paren<Char[length]>& str)
		XIEITE_ARROW(xieite::isupper(xieite::make_str_view(str)))
}

#endif
