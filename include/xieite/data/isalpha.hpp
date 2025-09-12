#ifndef DETAIL_XIEITE_HEADER_DATA_ISALPHA
#	define DETAIL_XIEITE_HEADER_DATA_ISALPHA
#
#	include <string>
#	include <string_view>
#	include "../data/islower.hpp"
#	include "../data/isupper.hpp"
#	include "../data/make_str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool isalpha(xieite::is_char auto c) noexcept {
		return xieite::islower(c) || xieite::isupper(c);
	}

	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr bool isalpha(std::basic_string_view<Char, Traits> strv) noexcept {
		for (Char c : strv) {
			if (!xieite::isalpha(c)) {
				return false;
			}
		}
		return true;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr bool isalpha(const std::basic_string<Char, Traits, Alloc>& str) noexcept {
		return xieite::isalpha(xieite::make_str_view(str));
	}

	template<xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr bool isalpha(const xieite::paren<Char[length]>& str) noexcept {
		return xieite::isalpha(xieite::make_str_view(str));
	}
}

#endif
