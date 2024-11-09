export module xieite:trunc;

import std;
import :sv;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> trunc(std::basic_string<Ch, Traits, Alloc> str, std::size_t size, xieite::sv<Ch, Traits> sfx = "") noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		return (str.size() <= size)
			? str
			: ((sfx.size() > size)
				? Str(sfx.substr(0, size))
				: (str.substr(0, size - sfx.size()) + sfx));
	}
}
