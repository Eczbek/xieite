export module xieite:unquot;

import std;
import :str_rplc;
import :substr;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> unquot(std::basic_string_view<Ch, Traits> strv, Ch delim = '"', Ch esc = '\\') noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		strv.remove_prefix(strv[0] == delim);
		strv.remove_suffix(strv.back() == delim);
		return (delim == esc)
			? xieite::str_rplc(strv, Str(1, esc) + delim, delim)
			: xieite::str_rplc(xieite::str_rplc(strv, Str(2, esc), esc), Str(1, esc) + delim, delim);
	}
}
