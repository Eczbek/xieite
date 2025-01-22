export module xieite:trim_back;

import std;
import :id;
import :substr;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> trim_back(std::basic_string_view<Ch, Traits> strv, xieite::id<std::basic_string_view<Ch, Traits>> chars) noexcept {
		return xieite::substr(strv, 0, strv.find_last_not_of(chars), 0, 1);
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> trim_back(std::basic_string_view<Ch, Traits> strv, Ch c) noexcept {
		return xieite::substr(strv, 0, strv.find_last_not_of(c), 0, 1);
	}
}
