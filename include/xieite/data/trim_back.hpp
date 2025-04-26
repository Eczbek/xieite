#ifndef DETAIL_XIEITE_HEADER_DATA_TRIM_BACK
#	define DETAIL_XIEITE_HEADER_DATA_TRIM_BACK
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../data/str_view.hpp"
#	include "../data/substr.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<typename Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr auto trim_back(std::basic_string_view<Char, Traits> strv, auto&& chars)
		XIEITE_ARROW(xieite::substr(strv, 0, strv.find_last_not_of(XIEITE_FWD(chars)), 0, 1))

	template<typename Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr auto trim_back(const std::basic_string<Char, Traits>& str, auto&& chars)
		XIEITE_ARROW(xieite::trim_back(xieite::str_view(str), XIEITE_FWD(chars)))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, std::size_t length>
	[[nodiscard]] constexpr auto trim_back(const xieite::paren<Char[length]>& str, auto&& chars)
		XIEITE_ARROW(xieite::trim_back(xieite::str_view<Char, Traits>(str), XIEITE_FWD(chars)))
}

#endif
