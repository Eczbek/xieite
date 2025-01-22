export module xieite:str_before;

import std;
import :id;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_before(std::basic_string_view<Ch, Traits> strv, xieite::id<std::basic_string_view<Ch, Traits>> end) noexcept {
		return strv.substr(0, strv.rfind(end));
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_before(std::basic_string_view<Ch, Traits> strv, Ch end) noexcept {
		return strv.substr(0, strv.rfind(end));
	}
}
