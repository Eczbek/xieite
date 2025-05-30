#ifndef DETAIL_XIEITE_HEADER_DATA_SUBSTR
#	define DETAIL_XIEITE_HEADER_DATA_SUBSTR
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../data/str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<typename Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> substr(std::basic_string_view<Char, Traits> strv, std::size_t start, std::size_t end = std::string::npos, std::size_t start_offset = 0, std::size_t end_offset = 0) noexcept {
		if (start == std::string::npos) {
			return "";
		}
		if (end == std::string::npos) {
			return strv.substr(start + start_offset);
		}
		return strv.substr(start + start_offset, end - start + end_offset);
	}

	template<typename Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr auto substr(const std::basic_string<Char, Traits>& str, std::size_t start, std::size_t end = std::string::npos, std::size_t start_offset = 0, std::size_t end_offset = 0)
		XIEITE_ARROW(xieite::substr(xieite::str_view(str), start, end, start_offset, end_offset))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, std::size_t length>
	[[nodiscard]] constexpr auto substr(const xieite::paren<Char[length]>& str, std::size_t start, std::size_t end = std::string::npos, std::size_t start_offset = 0, std::size_t end_offset = 0)
		XIEITE_ARROW(xieite::substr(xieite::str_view<Char, Traits>(str), start, end, start_offset, end_offset))
}

#endif
