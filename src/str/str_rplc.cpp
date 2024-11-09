export module xieite:str_rplc;

import std;
import :sv;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_rplc(std::basic_string<Ch, Traits, Alloc> str, xieite::sv<Ch, Traits> orig, xieite::sv<Ch, Traits> replc) noexcept {
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
