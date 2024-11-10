export module xieite:str_betw;

import std;
import :str_after;
import :str_before;
import :sv;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_betw(std::basic_string_view<Ch, Traits> str, std::type_identity_t<xieite::sv<Ch, Traits>> start, std::type_identity_t<xieite::sv<Ch, Traits>> end) noexcept {
		return xieite::str_before(xieite::str_after(str, start), end);
	}
}