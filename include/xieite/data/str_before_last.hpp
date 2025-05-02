#ifndef DETAIL_XIEITE_HEADER_DATA_STR_BEFORE_LAST
#	define DETAIL_XIEITE_HEADER_DATA_STR_BEFORE_LAST
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../data/str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<typename Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr auto str_before_last(std::basic_string_view<Char, Traits> strv, auto&& delim)
		XIEITE_ARROW(strv.substr(0, strv.rfind(XIEITE_FWD(delim))))

	template<typename Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr auto str_before_last(const std::basic_string<Char, Traits>& str, auto&& delim)
		XIEITE_ARROW(xieite::str_before_last(xieite::str_view(str), XIEITE_FWD(delim)))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, std::size_t length>
	[[nodiscard]] constexpr auto str_before_last(const xieite::paren<Char[length]>& str, auto&& delim)
		XIEITE_ARROW(xieite::str_before_last(xieite::str_view<Char, Traits>(str), XIEITE_FWD(delim)))
}

#endif
