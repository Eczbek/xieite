export module xieite:str_trunc;

import std;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_trunc(std::basic_string_view<Ch, Traits>& strv, std::size_t size, std::basic_string_view<Ch, Traits> sfx = "") noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		return (strv.size() <= size)
			? Str(strv)
			: ((sfx.size() > size)
				? Str(sfx.substr(0, size))
				: (Str(strv.substr(0, size - sfx.size())) + Str(sfx)));
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_trunc(std::basic_string_view<Ch, Traits> strv, std::size_t size, Ch sfx) noexcept {
		return xieite::str_trunc<Ch, Traits, Alloc>(strv, size, std::basic_string_view<Ch, Traits>(&sfx, 1));
	}
}
