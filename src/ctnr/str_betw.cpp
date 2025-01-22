export module xieite:str_betw;

import std;
import :id;
import :str_after;
import :str_before;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_betw(std::basic_string_view<Ch, Traits> strv, xieite::id<std::basic_string_view<Ch, Traits>> start, xieite::id<std::basic_string_view<Ch, Traits>> end) noexcept {
		return xieite::str_before(xieite::str_after(strv, start), end);
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_betw(std::basic_string_view<Ch, Traits> strv, Ch start, xieite::id<std::basic_string_view<Ch, Traits>> end) noexcept {
		return xieite::str_before(xieite::str_after(strv, start), end);
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_betw(std::basic_string_view<Ch, Traits> strv, xieite::id<std::basic_string_view<Ch, Traits>> start, Ch end) noexcept {
		return xieite::str_before(xieite::str_after(strv, start), end);
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_betw(std::basic_string_view<Ch, Traits> strv, Ch start, Ch end) noexcept {
		return xieite::str_before(xieite::str_after(strv, start), end);
	}
}
