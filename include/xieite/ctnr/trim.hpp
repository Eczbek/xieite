#ifndef DETAIL_XIEITE_HEADER_CTNR_TRIM
#	define DETAIL_XIEITE_HEADER_CTNR_TRIM
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../ctnr/str_view.hpp"
#	include "../ctnr/trim_back.hpp"
#	include "../ctnr/trim_front.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto trim(std::basic_string_view<Ch, Traits> strv, auto&& chars)
		XIEITE_ARROW(xieite::trim_back(xieite::trim_front(strv, chars), chars))

	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto trim(const std::basic_string<Ch, Traits>& str, auto&& chars)
		XIEITE_ARROW(xieite::trim(xieite::str_view(str), XIEITE_FWD(chars)))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto trim(const xieite::paren<Ch[n]>& str, auto&& chars)
		XIEITE_ARROW(xieite::trim(xieite::str_view<Ch, Traits>(str), XIEITE_FWD(chars)))
}

#endif
