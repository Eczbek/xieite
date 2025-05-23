#ifndef DETAIL_XIEITE_HEADER_DATA_STR_AFTER_LAST
#	define DETAIL_XIEITE_HEADER_DATA_STR_AFTER_LAST
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../data/str_view.hpp"
#	include "../data/strlen.hpp"
#	include "../data/substr.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<typename Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr auto str_after_last(std::basic_string_view<Char, Traits> strv, auto&& delim)
		XIEITE_ARROW(xieite::substr(strv, strv.rfind(delim), std::string::npos, xieite::strlen(delim)))

	template<typename Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr auto str_after_last(const std::basic_string<Char, Traits>& str, auto&& delim)
		XIEITE_ARROW(xieite::str_after_last(xieite::str_view(str), XIEITE_FWD(delim)))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, std::size_t length>
	[[nodiscard]] constexpr auto str_after_last(const xieite::paren<Char[length]>& str, auto&& delim)
		XIEITE_ARROW(xieite::str_after_last(xieite::str_view<Char, Traits>(str), XIEITE_FWD(delim)))
}

#endif
