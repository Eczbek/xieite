export module xieite:pad_front;

import std;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> pad_front(std::basic_string_view<Ch, Traits, Alloc> strv, std::size_t size, Ch c = ' ') noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		return (strv.size() < size)
			? ((size - strv.size(), c) + Str(strv))
			: Str(strv);
	}
}
