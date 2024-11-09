export module xieite:str_before;

import std;
import :sv;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_before(std::basic_string_view<Ch, Traits> str, xieite::sv<Ch, Traits> end) noexcept {
		return str.substr(0, str.rfind(end));
	}
}
