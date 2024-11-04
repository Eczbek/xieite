export module xieite:quote;

import std;
import :str_replace;

export namespace xieite {
	template<typename C = char, typename Traits = std::char_traits<C>, typename Alloc = std::allocator<C>>
	[[nodiscard]] constexpr std::basic_string<C, Traits, Alloc> quote(std::basic_string_view<C, Traits> str, C delim = '"', C esc = '\\') noexcept {
		using Str = std::basic_string<C, Traits, Alloc>;
		auto result = Str(1, delim);
		const Str esc_delim = Str(1, esc) + delim;
		if (delim == esc) {
			result += xieite::str_replace(str, delim, esc_delim);
		} else {
			result += xieite::str_replace(xieite::str_replace(str, esc, Str(2, esc)), delim, esc_delim);
		}
		return result + delim;
	}
}
