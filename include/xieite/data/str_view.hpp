#ifndef DETAIL_XIEITE_HEADER_DATA_STR_VIEW
#	define DETAIL_XIEITE_HEADER_DATA_STR_VIEW
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<typename Char>
	[[nodiscard]] constexpr auto str_view(std::basic_string_view<Char> strv)
		XIEITE_ARROW(strv)

	template<typename Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr auto str_view(const std::basic_string<Char, Traits>& str)
		XIEITE_ARROW(std::basic_string_view<Char, Traits>(str))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr auto str_view(const Char* str, std::size_t length)
		XIEITE_ARROW(std::basic_string_view<Char, Traits>(str, length))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, std::size_t length>
	[[nodiscard]] constexpr auto str_view(const xieite::paren<Char[length]>& str)
		XIEITE_ARROW(std::basic_string_view<Char, Traits>(str, length))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr auto str_view(Char&& c = {})
		XIEITE_ARROW(std::basic_string_view<Char, Traits>(&c, 1))
}

#endif
