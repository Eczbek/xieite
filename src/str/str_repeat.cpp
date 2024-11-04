export module xieite:str_repeat;

import std;
import :sv;

export namespace xieite {
	template<typename C = char, typename Traits = std::char_traits<C>, typename Alloc = std::allocator<C>>
	[[nodiscard]] constexpr std::basic_string<C, Traits, Alloc> str_repeat(std::size_t n, xieite::sv<C, Traits> str) noexcept {
		std::basic_string<C, Traits, Alloc> result;
		result.reserve(str.size() * n);
		while (n--) {
			result += str;
		}
		return result;
	}
}
