export module xieite:str_repeat;

import std;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_repeat(std::size_t n, std::basic_string_view<Ch, Traits> strv) noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		Str result;
		result.reserve(strv.size() * n);
		while (n--) {
			result += Str(strv);
		}
		return result;
	}
}
