#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include "../ctnr/str_view.hpp"
#include "../ctnr/strlen.hpp"
#include "../ctnr/substr.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto str_after(std::basic_string_view<Ch, Traits> strv, auto&& delim)
		XIEITE_ARROW(xieite::substr(strv, strv.find(delim), std::string::npos, xieite::strlen(delim)))

	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto str_after(const std::basic_string<Ch, Traits>& str, auto&& delim)
		XIEITE_ARROW(xieite::str_after(xieite::str_view(str), XIEITE_FWD(delim)))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto str_after(const Ch(& str)[n], auto&& delim)
		XIEITE_ARROW(xieite::str_after(xieite::str_view<Ch, Traits>(str), XIEITE_FWD(delim)))
}
