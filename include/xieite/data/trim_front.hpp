#ifndef DETAIL_XIEITE_HEADER_DATA_TRIM_FRONT
#	define DETAIL_XIEITE_HEADER_DATA_TRIM_FRONT
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
	[[nodiscard]] constexpr auto trim_front(std::basic_string_view<Char, Traits> strv, auto&& chars)
		XIEITE_ARROW(strv.substr(strv.find_first_not_of(XIEITE_FWD(chars))))

	template<typename Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr auto trim_front(const std::basic_string<Char, Traits>& str, auto&& chars)
		XIEITE_ARROW(xieite::trim_front(xieite::str_view(str), XIEITE_FWD(chars)))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, std::size_t length>
	[[nodiscard]] constexpr auto trim_front(const xieite::paren<Char[length]>& str, auto&& chars)
		XIEITE_ARROW(xieite::trim_front(xieite::str_view<Char, Traits>(str), XIEITE_FWD(chars)))
}

#endif
