#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include "../ctnr/str_view.hpp"
#include "../ctnr/substr.hpp"
#include "../meta/group.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto trim_back(std::basic_string_view<Ch, Traits> strv, auto&& chars)
		XIEITE_ARROW(xieite::substr(strv, 0, strv.find_last_not_of(XIEITE_FWD(chars)), 0, 1))

	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto trim_back(const std::basic_string<Ch, Traits>& str, auto&& chars)
		XIEITE_ARROW(xieite::trim_back(xieite::str_view(str), XIEITE_FWD(chars)))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto trim_back(const xieite::group<Ch[n]>& str, auto&& chars)
		XIEITE_ARROW(xieite::trim_back(xieite::str_view<Ch, Traits>(str), XIEITE_FWD(chars)))
}
