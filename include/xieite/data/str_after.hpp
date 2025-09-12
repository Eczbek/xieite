#ifndef DETAIL_XIEITE_HEADER_DATA_STR_AFTER
#	define DETAIL_XIEITE_HEADER_DATA_STR_AFTER
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../data/make_str_view.hpp"
#	include "../data/strlen.hpp"
#	include "../data/substr.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr auto str_after(std::basic_string_view<Char, Traits> strv, auto&& delim)
		XIEITE_ARROW(xieite::substr(strv, strv.find(delim), std::string::npos, xieite::strlen(delim)))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr auto str_after(const std::basic_string<Char, Traits>& str, auto&& delim)
		XIEITE_ARROW(xieite::str_after(xieite::make_str_view(str), XIEITE_FWD(delim)))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, std::size_t length>
	[[nodiscard]] constexpr auto str_after(const xieite::paren<Char[length]>& str, auto&& delim)
		XIEITE_ARROW(xieite::str_after(xieite::make_str_view<Char, Traits>(str), XIEITE_FWD(delim)))
}

#endif
