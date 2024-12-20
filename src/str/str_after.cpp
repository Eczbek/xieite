export module xieite:str_after;

import std;
import :id;
import :substr;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_after(std::basic_string_view<Ch, Traits> strv, xieite::id<std::basic_string_view<Ch, Traits>> start) noexcept {
		return xieite::substr(strv, strv.find(start), std::string::npos, start.size());
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_after(std::basic_string_view<Ch, Traits> strv, Ch start) noexcept {
		return xieite::substr(strv, strv.find(start), std::string::npos, 1);
	}
}
