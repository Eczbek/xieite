export module xieite:unquote;

import std;
import :str_replace;

export namespace xieite {
	template<typename C = char, typename Traits = std::char_traits<C>, typename Alloc = std::allocator<C>>
	[[nodiscard]] constexpr std::basic_string<C, Traits, Alloc> unquote(std::basic_string<C, Traits> str, C delim = '"', C esc = '\\') noexcept {
		using Str = std::basic_string<C, Traits, Alloc>;
		str = str.substr(str[0] == delim, str.size() - (str[str.size() - 1] == delim));
		const Str esc_delim = Str(1, esc) + delim;
		if (delim == esc) {
			return xieite::str_replace(std::move(str), esc_delim, delim);
		} else {
			return xieite::str_replace(xieite::str_replace(std::move(str), Str(2, esc), esc), esc_delim, delim);
		}
	}
}
