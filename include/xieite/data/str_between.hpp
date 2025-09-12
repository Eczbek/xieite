#ifndef DETAIL_XIEITE_HEADER_DATA_STR_BETWEEN
#	define DETAIL_XIEITE_HEADER_DATA_STR_BETWEEN
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../data/make_str_view.hpp"
#	include "../data/str_after.hpp"
#	include "../data/str_before.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> str_between(std::basic_string_view<Char, Traits> strv, auto&& a, auto&& b) noexcept {
		return xieite::str_after(xieite::str_before(strv, XIEITE_FWD(b)), XIEITE_FWD(a));
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> str_between(const std::basic_string<Char, Traits, Alloc>& str, auto&& a, auto&& b) noexcept {
		return xieite::str_between(xieite::make_str_view(str), XIEITE_FWD(a), XIEITE_FWD(b));
	}

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, std::size_t length>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> str_between(const xieite::paren<Char[length]>& str, auto&& a, auto&& b) noexcept {
		return xieite::str_between(xieite::make_str_view<Char, Traits>(str), XIEITE_FWD(a), XIEITE_FWD(b));
	}
}

#endif
