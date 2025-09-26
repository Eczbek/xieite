#ifndef DETAIL_XIEITE_HEADER_DATA_ISGRAPH
#	define DETAIL_XIEITE_HEADER_DATA_ISGRAPH
#
#	include <string>
#	include <string_view>
#	include "../data/isalnum.hpp"
#	include "../data/ispunct.hpp"
#	include "../data/make_str_view.hpp"
#	include "../meta/type.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool isgraph(xieite::is_char auto c) noexcept {
		return xieite::isalnum(c) || xieite::ispunct(c);
	}

	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr bool isgraph(
		std::basic_string_view<Char, Traits> strv
	) noexcept {
		for (Char c : strv) {
			if (!xieite::isgraph(c)) {
				return false;
			}
		}
		return true;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr bool isgraph(
		const std::basic_string<Char, Traits, Alloc>& str
	) noexcept {
		return xieite::isgraph(xieite::make_str_view(str));
	}

	template<xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr bool isgraph(
		const xieite::type<Char[length]>& str
	) noexcept {
		return xieite::isgraph(xieite::make_str_view(str));
	}
}

#endif
