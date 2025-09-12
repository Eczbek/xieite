#ifndef DETAIL_XIEITE_HEADER_DATA_TRIM
#	define DETAIL_XIEITE_HEADER_DATA_TRIM
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../data/make_str_view.hpp"
#	include "../data/trim_back.hpp"
#	include "../data/trim_front.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr auto trim(std::basic_string_view<Char, Traits> strv, auto&& chars)
		XIEITE_ARROW(xieite::trim_back(xieite::trim_front(strv, chars), chars))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr auto trim(const std::basic_string<Char, Traits>& str, auto&& chars)
		XIEITE_ARROW(xieite::trim(xieite::make_str_view(str), XIEITE_FWD(chars)))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, std::size_t length>
	[[nodiscard]] constexpr auto trim(const xieite::paren<Char[length]>& str, auto&& chars)
		XIEITE_ARROW(xieite::trim(xieite::make_str_view<Char, Traits>(str), XIEITE_FWD(chars)))
}

#endif
