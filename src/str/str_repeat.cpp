export module xieite:str_repeat;

import std;
import :sv;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_repeat(std::size_t n, xieite::sv<Ch, Traits> str) noexcept {
		std::basic_string<Ch, Traits, Alloc> result;
		result.reserve(str.size() * n);
		while (n--) {
			result += str;
		}
		return result;
	}
}
