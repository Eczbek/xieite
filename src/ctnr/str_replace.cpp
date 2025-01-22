export module xieite:str_replace;

import std;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_replace(std::basic_string_view<Ch, Traits> strv, std::basic_string_view<Ch, Traits> orig, std::basic_string_view<Ch, Traits> rplcmt) noexcept {
		auto result = std::basic_string<Ch, Traits, Alloc>(strv);
		std::size_t i = 0;
		while (true) {
			i = result.find(orig, i);
			if (i == std::string::npos) {
				break;
			}
			result.replace(i, orig.size(), rplcmt);
			++i;
		}
		return result;
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_replace(std::basic_string_view<Ch, Traits> strv, Ch orig, std::basic_string_view<Ch, Traits> rplcmt = "") noexcept {
		return xieite::str_replace(strv, std::basic_string_view<Ch, Traits>(&orig, 1), rplcmt);
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_replace(std::basic_string_view<Ch, Traits> strv, std::basic_string_view<Ch, Traits> orig, Ch rplcmt) noexcept {
		return xieite::str_replace(strv, orig, std::basic_string_view<Ch, Traits>(&rplcmt, 1));
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_replace(std::basic_string_view<Ch, Traits> strv, Ch orig, Ch rplcmt) noexcept {
		return xieite::str_replace(strv, std::basic_string_view<Ch, Traits>(&orig, 1), std::basic_string_view<Ch, Traits>(&rplcmt, 1));
	}
}
