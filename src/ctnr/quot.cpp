export module xieite:quot;

import std;
import :str_replace;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> quot(std::basic_string_view<Ch, Traits> strv, Ch delim = '"', Ch esc = '\\') noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		return (delim == esc)
			? (delim + xieite::str_replace(strv, delim, Str(1, esc) + delim) + delim)
			: (delim + xieite::str_replace(xieite::str_replace(strv, esc, Str(2, esc)), delim, Str(1, esc) + delim) + delim);
	}
}
