#ifndef DETAIL_XIEITE_HEADER_CTNR_SUBSTR
#	define DETAIL_XIEITE_HEADER_CTNR_SUBSTR
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../ctnr/str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> substr(std::basic_string_view<Ch, Traits> strv, std::size_t start, std::size_t end = std::string::npos, std::size_t start_offset = 0, std::size_t end_offset = 0) noexcept {
		if (start == std::string::npos) {
			return "";
		}
		if (end == std::string::npos) {
			return strv.substr(start + start_offset);
		}
		return strv.substr(start + start_offset, end - start + end_offset);
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto substr(const std::basic_string<Ch, Traits>& str, std::size_t start, std::size_t end = std::string::npos, std::size_t start_offset = 0, std::size_t end_offset = 0)
		XIEITE_ARROW(xieite::substr(xieite::str_view(str), start, end, start_offset, end_offset))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto substr(const xieite::paren<Ch[n]>& str, std::size_t start, std::size_t end = std::string::npos, std::size_t start_offset = 0, std::size_t end_offset = 0)
		XIEITE_ARROW(xieite::substr(xieite::str_view<Ch, Traits>(str), start, end, start_offset, end_offset))
}

#endif
