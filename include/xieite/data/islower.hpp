#ifndef DETAIL_XIEITE_HEADER_DATA_ISLOWER
#	define DETAIL_XIEITE_HEADER_DATA_ISLOWER
#
#	include <string>
#	include <string_view>
#	include "../data/str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/cases.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool islower(xieite::is_char auto c) noexcept {
		switch (c) {
		XIEITE_CASES('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'):
			return true;
		}
		return false;
	}

	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr bool islower(std::basic_string_view<Char, Traits> strv) noexcept {
		for (Char c : strv) {
			if (!xieite::islower(c)) {
				return false;
			}
		}
		return true;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr auto islower(const std::basic_string<Char, Traits, Alloc>& str)
		XIEITE_ARROW(xieite::islower(xieite::str_view(str)))

	template<xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr auto islower(const xieite::paren<Char[length]>& str)
		XIEITE_ARROW(xieite::islower(xieite::str_view(str)))
}

#endif
