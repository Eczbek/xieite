export module xieite:quot;

import std;
import :str_rplc;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> quot(std::basic_string<Ch, Traits, Alloc> str, Ch delim = '"', Ch esc = '\\') noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		const Str esc_delim = Str(1, esc) + delim;
		if (delim == esc) {
			return delim + xieite::str_rplc(str, delim, esc_delim) + delim;
		}
		return delim + xieite::str_rplc(xieite::str_rplc(str, esc, Str(2, esc)), delim, esc_delim) + delim;
	}
}
