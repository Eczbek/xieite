#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include "../ctnr/str_after.hpp"
#include "../ctnr/str_before.hpp"
#include "../ctnr/str_view.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto str_betw(std::basic_string_view<Ch, Traits> strv, auto&& a, auto&& b)
		XIEITE_ARROW(xieite::str_after(xieite::str_before(strv, XIEITE_FWD(b)), XIEITE_FWD(a)))

	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto str_betw(const std::basic_string<Ch, Traits>& str, auto&& a, auto&& b)
		XIEITE_ARROW(xieite::str_betw(xieite::str_view(str), XIEITE_FWD(a), XIEITE_FWD(b)))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto str_betw(Ch(& str)[n], auto&& a, auto&& b)
		XIEITE_ARROW(xieite::str_betw(xieite::str_view<Ch, Traits>(str), XIEITE_FWD(a), XIEITE_FWD(b)))
}
