#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include "../ctnr/str_view.hpp"
#include "../meta/group.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto str_before(std::basic_string_view<Ch, Traits> strv, auto&& delim)
		XIEITE_ARROW(strv.substr(0, strv.find(XIEITE_FWD(delim))))

	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto str_before(const std::basic_string<Ch, Traits>& str, auto&& delim)
		XIEITE_ARROW(xieite::str_before(xieite::str_view(str), XIEITE_FWD(delim)))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto str_before(const xieite::group<Ch[n]>& str, auto&& delim)
		XIEITE_ARROW(xieite::str_before(xieite::str_view<Ch, Traits>(str), XIEITE_FWD(delim)))
}
