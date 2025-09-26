#ifndef DETAIL_XIEITE_HEADER_DATA_ISPRINT
#	define DETAIL_XIEITE_HEADER_DATA_ISPRINT
#
#	include <string>
#	include <string_view>
#	include "../data/isgraph.hpp"
#	include "../data/make_str_view.hpp"
#	include "../meta/type.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool isprint(xieite::is_char auto c) noexcept {
		return xieite::isgraph(c) || (c == ' ');
	}

	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr bool isprint(
		std::basic_string_view<Char, Traits> strv
	) noexcept {
		for (Char c : strv) {
			if (!xieite::isprint(c)) {
				return false;
			}
		}
		return true;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr bool isprint(
		const std::basic_string<Char, Traits, Alloc>& str
	) noexcept {
		return xieite::isprint(xieite::make_str_view(str));
	}

	template<xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr bool isprint(
		const xieite::type<Char[length]>& str
	) noexcept {
		return xieite::isprint(xieite::make_str_view(str));
	}
}

#endif
