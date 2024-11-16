export module xieite:substr;

import std;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits, Alloc> substr(std::basic_string_view<Ch, Traits, Alloc> str, std::size_t start, std::size_t end = str.size(), std::size_t start_offset = 0, std::size_t end_offset = 0) noexcept {
		if (start == std::string::npos) {
			return "";
		}
		if (end == std::string::npos) {
			return str.substr(start + start_offset);
		}
		return str.substr(start + start_offset, end - start + end_offset);
	}
}
