#pragma once

#include <string>
#include <string_view>
#include "../ctnr/substr.hpp"
#include "../meta/id.hpp"

namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> trim(std::basic_string_view<Ch, Traits> strv, xieite::id<std::basic_string_view<Ch, Traits>> chars) noexcept {
		return xieite::substr(strv, strv.find_first_not_of(chars), strv.find_last_not_of(chars), 0, 1);
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> trim(std::basic_string_view<Ch, Traits> strv, Ch c) noexcept {
		return xieite::trim(strv, std::basic_string_view<Ch, Traits>(&c, 1));
	}
}
