#ifndef DETAIL_XIEITE_HEADER_DATA_ISPUNCT
#	define DETAIL_XIEITE_HEADER_DATA_ISPUNCT
#
#	include <string>
#	include <string_view>
#	include "../data/make_str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/cases.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool ispunct(xieite::is_char auto c) noexcept {
		switch (c) {
		XIEITE_CASES('!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`', '{', '|', '}', '~'):
			return true;
		}
		return false;
	}

	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr bool ispunct(std::basic_string_view<Char, Traits> strv) noexcept {
		for (Char c : strv) {
			if (!xieite::ispunct(c)) {
				return false;
			}
		}
		return true;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr auto ispunct(const std::basic_string<Char, Traits, Alloc>& str)
		XIEITE_ARROW(xieite::ispunct(xieite::make_str_view(str)))

	template<xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr auto ispunct(const xieite::paren<Char[length]>& str)
		XIEITE_ARROW(xieite::ispunct(xieite::make_str_view(str)))
}

#endif
