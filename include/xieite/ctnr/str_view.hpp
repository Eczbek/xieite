#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include "../pp/arrow.hpp"
#include "../trait/is_ch.hpp"
#include "../trait/is_ch_ptr.hpp"
#include "../trait/rm_ptr.hpp"

namespace xieite {
	template<typename Ch>
	[[nodiscard]] constexpr auto str_view(std::basic_string_view<Ch> strv)
		XIEITE_ARROW(strv)

	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto str_view(const std::basic_string<Ch, Traits>& str)
		XIEITE_ARROW(std::basic_string_view<Ch, Traits>(str))

	template<xieite::is_ch_ptr Str, typename Traits = std::char_traits<xieite::rm_ptr<Str>>>
	[[nodiscard]] constexpr auto str_view(Str str, std::size_t n)
		XIEITE_ARROW(std::basic_string_view<xieite::rm_ptr<Str>, Traits>(str, n))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto str_view(Ch(& str)[n])
		XIEITE_ARROW(std::basic_string_view<Ch, Traits>(str, n))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto str_view(Ch&& c = {})
		XIEITE_ARROW(std::basic_string_view<Ch, Traits>(&c, 1))
}
