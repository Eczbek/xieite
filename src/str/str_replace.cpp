export module xieite:str_replace;

import std;
import :sv;

export namespace xieite {
	template<typename C = char, typename Traits = std::char_traits<C>, typename Alloc = std::allocator<C>>
	[[nodiscard]] constexpr std::basic_string<C, Traits, Alloc> str_replace(std::basic_string<C, Traits, Alloc> str, xieite::sv<C, Traits> orig, xieite::sv<C, Traits> replc) noexcept {
		std::size_t i = 0;
		while (true) {
			i = str.find(orig, i);
			if (i == std::string::npos) {
				break;
			}
			str.replace(i, orig.size(), replc);
			++i;
		}
		return str;
	}
}
