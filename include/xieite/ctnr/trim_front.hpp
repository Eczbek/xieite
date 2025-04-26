#ifndef DETAIL_XIEITE_HEADER_CTNR_TRIM_FRONT
#	define DETAIL_XIEITE_HEADER_CTNR_TRIM_FRONT
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../ctnr/str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto trim_front(std::basic_string_view<Ch, Traits> strv, auto&& chars)
		XIEITE_ARROW(strv.substr(strv.find_first_not_of(XIEITE_FWD(chars))))

	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto trim_front(const std::basic_string<Ch, Traits>& str, auto&& chars)
		XIEITE_ARROW(xieite::trim_front(xieite::str_view(str), XIEITE_FWD(chars)))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto trim_front(const xieite::paren<Ch[n]>& str, auto&& chars)
		XIEITE_ARROW(xieite::trim_front(xieite::str_view<Ch, Traits>(str), XIEITE_FWD(chars)))
}

#endif
