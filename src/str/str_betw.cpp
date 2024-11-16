export module xieite:str_betw;

import std;
import :str_after;
import :str_before;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_betw(std::basic_string_view<Ch, Traits> strv, std::basic_string_view<Ch, Traits> start, std::basic_string_view<Ch, Traits> end) noexcept {
		return xieite::str_before(xieite::str_after(strv, start), end);
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_betw(std::basic_string_view<Ch, Traits> strv, Ch start, std::basic_string_view<Ch, Traits> end) noexcept {
		return xieite::str_before(xieite::str_after(strv, start), end);
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_betw(std::basic_string_view<Ch, Traits> strv, std::basic_string_view<Ch, Traits> start, Ch end) noexcept {
		return xieite::str_before(xieite::str_after(strv, start), end);
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_betw(std::basic_string_view<Ch, Traits> strv, Ch start, Ch end) noexcept {
		return xieite::str_before(xieite::str_after(strv, start), end);
	}
}
